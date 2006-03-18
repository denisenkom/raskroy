using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Windows.Forms;

using Denisenko.Cutting;
using Denisenko.Cutting.Optimizing;

namespace Denisenko.Cutting.CutOptima
{
	class Mediator
	{
		private static Mediator m_instance;

		public static Mediator Instance 
		{
			get 
			{
				if (m_instance == null)
					m_instance = new Mediator();
				return m_instance;
			} 
		}

		/*public void OpenReferenceDetails()
		{
			ReferenceDetailsForm.Instance.MdiParent = MainForm.Instance;
			ReferenceDetailsForm.Instance.Show();
		}*/

		public void OpenListsEditor()
		{
			DetailsListsForm detailListsForm = new DetailsListsForm();
			detailListsForm.MdiParent = MainForm.Instance;
			detailListsForm.Show();
		}

		public void OpenListEditor(Int32 listID)
		{
			DetailsListForm editor = new DetailsListForm(listID);
			editor.MdiParent = MainForm.Instance;
			editor.Show();
		}

		internal void AddDetailsList()
		{
			DetailsListForm editor = new DetailsListForm();
			editor.MdiParent = MainForm.Instance;
			editor.Show();
		}

		public PropertyTypes PropertyTypes
		{
			get { throw new NotImplementedException(); }
		}

		private ProgressForm _progressForm;
		private OptimizingJob _job;

		private delegate void UpdateProgressHandler(Int32 progress);

		private void OnCuttingProgressUpdate(OptimizingJob job, Int32 progress)
		{
			_progressForm.BeginInvoke(new UpdateProgressHandler(_progressForm.UpdateProgress), progress);
		}

		private delegate void CloseFormHandler();

		private void OnCuttingFinished(OptimizingJob job)
		{
			_progressForm.BeginInvoke(new CloseFormHandler(_progressForm.Close));
		}

		private void OnCuttingError(OptimizingJob job, Exception error)
		{
			MessageBox.Show(error.Message);
			_progressForm.BeginInvoke(new CloseFormHandler(_progressForm.Close));
		}

		internal void OptimizeDetailsList(Int32 detailsIistID)
		{
			_job = new OptimizingJob();
			_job.Load(Properties.Settings.Default.CutOptimaConnectionString,
				new Int32[] { detailsIistID });
			_progressForm = new ProgressForm();
			_progressForm.StartPosition = FormStartPosition.CenterParent;
			_progressForm.Pause += OnPause;
			_progressForm.Resume += OnResume;
			_progressForm.Cancel += OnCancel;
			_job.ProgressUpdate += OnCuttingProgressUpdate;
			_job.Finished += OnCuttingFinished;
			_job.Error += OnCuttingError;
			_job.AsyncExecute();

			_progressForm.ShowDialog();
			if(!_job.Canceled)
				ShowCuttingResult(_job.Result);
		}

		private void ShowCuttingResult(List<CuttingScheme> result)
		{
			CuttingResultForm form = new CuttingResultForm();
			form.MdiParent = MainForm.Instance;
			form.DataSource = result;
			form.Show();
		}

		private void OnPause(ProgressForm sender)
		{
			_job.Pause();
		}

		private void OnResume(ProgressForm sender)
		{
			_job.Resume();
		}

		private void OnCancel(ProgressForm sender)
		{
			_job.Cancel();
		}

		internal void OpenSheetsEditor()
		{
			SheetsListForm form = new SheetsListForm();
			form.MdiParent = MainForm.Instance;
			form.Show();
		}

		internal void OpenMaterialsEditor()
		{
			MaterialsForm form = new MaterialsForm();
			form.MdiParent = MainForm.Instance;
			form.Show();
		}

		internal void LoadCuttingCommand()
		{
			try
			{
				OpenFileDialog dialog = new OpenFileDialog();
				dialog.DefaultExt = "cutting";
				dialog.Filter = "Файлы раскроя (*.cutting)|*.cutting|Все файлы (*.*)|*.*";
				if (dialog.ShowDialog() == DialogResult.Cancel)
					return;
				FileStream stream = File.OpenRead(dialog.FileName);
				BinaryFormatter formatter = new BinaryFormatter();
				CuttingResultForm form = new CuttingResultForm();
				form.DataSource = (List<CuttingScheme>)formatter.Deserialize(stream);
				form.MdiParent = MainForm.Instance;
				form.Show();
				stream.Close();
			}
			catch (SerializationException)
			{
				MessageBox.Show("Файл имеет не правильный формат или поврежден");
			}
		}

		internal void SaveCuttingCommand(List<CuttingScheme> cutting)
		{
			SaveFileDialog dialog = new SaveFileDialog();
			dialog.AddExtension = true;
			dialog.DefaultExt = "cutting";
			dialog.Filter = "Файлы раскроя (*.cutting)|*.cutting|Все файлы (*.*)|*.*";
			if (dialog.ShowDialog() == DialogResult.Cancel)
				return;
			FileStream stream = File.Create(dialog.FileName);
			BinaryFormatter formatter = new BinaryFormatter();
			formatter.Serialize(stream, cutting);
			stream.Close();
		}

		internal void ExportLC4Command(List<CuttingScheme> cuttings)
		{
			Denisenko.Cutting.Converting.LC4Convertor convertor = new Denisenko.Cutting.Converting.LC4Convertor();

			LC4.LC4Document lc4Document = convertor.Convert(cuttings);
			Denisenko.Cutting.LC4.LC4Parser parser = new Denisenko.Cutting.LC4.LC4Parser();
			SaveFileDialog dialog = new SaveFileDialog();
			dialog.AddExtension = true;
			dialog.DefaultExt = "lc4";
			dialog.Filter = "Файлы раскроя (*.lc4)|*.lc4|Все файлы (*.*)|*.*";
			if (dialog.ShowDialog() == DialogResult.Cancel)
				return;
			lc4Document.InternalName = Path.GetFileNameWithoutExtension(dialog.FileName);
			lc4Document.Description = "manually generated";
			parser.Save(dialog.FileName, FileMode.Create, lc4Document);
		}

		internal void OpenCuttingParametersCommand()
		{
			CuttingParametersForm form = new CuttingParametersForm();
			form.MdiParent = MainForm.Instance;
			form.Show();
		}

		internal void CuttingCommand()
		{
			CuttingWizard.CuttingWizard wizard = new CuttingWizard.CuttingWizard();
			if (wizard.Execute(MainForm.Instance))
			{
				_job = new OptimizingJob();
				_job.Load(Properties.Settings.Default.CutOptimaConnectionString,
					wizard.DetailsListsIDs, wizard.SheetsIDs);
				_progressForm = new ProgressForm();
				_progressForm.StartPosition = FormStartPosition.CenterParent;
				_progressForm.Pause += OnPause;
				_progressForm.Resume += OnResume;
				_progressForm.Cancel += OnCancel;
				_job.ProgressUpdate += OnCuttingProgressUpdate;
				_job.Finished += OnCuttingFinished;
				_job.Error += OnCuttingError;
				_job.AsyncExecute();

				_progressForm.ShowDialog();
				if (!_job.Canceled)
					ShowCuttingResult(_job.Result);
			}
		}

		internal void Startup()
		{
			DBManager.Instance.Startup(MainForm.Instance);
		}

		internal DialogResult AskUserToSaveChanges()
		{
			return MessageBox.Show("Сохранить изменения?", "CutOptima", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Exclamation);
		}

		internal void DataGridView_DataError(object sender, DataGridViewDataErrorEventArgs e)
		{
			if (e.Exception != null && e.Exception is NoNullAllowedException && e.Context == DataGridViewDataErrorContexts.Commit)
			{
				MessageBox.Show(e.Exception.Message, null, MessageBoxButtons.OK, MessageBoxIcon.Error);
				e.Cancel = true;
				e.ThrowException = false;
			}
			else
			{
				MessageBox.Show(String.Format("Необработанное исключение: {0}", e.Exception), null, MessageBoxButtons.OK, MessageBoxIcon.Error);
				e.Cancel = false;
				e.ThrowException = false;
			}
		}
	}
}
