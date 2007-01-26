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
			DetailsListForm editor = new DetailsListForm(DetailsListOpenType.Open, listID);
			editor.MdiParent = MainForm.Instance;
			editor.Show();
		}

		internal void AddDetailsList()
		{
			DetailsListForm editor = new DetailsListForm(DetailsListOpenType.AddNew);
			editor.MdiParent = MainForm.Instance;
			editor.Show();
		}

		public PropertyTypes PropertyTypes
		{
			get { throw new NotImplementedException(); }
		}

		private ProgressForm _progressForm;
		private OptimizingJob _job;

		private delegate void CloseFormHandler();

		internal void OptimizeDetailsList(Int32 detailsIistID)
		{
			_job = new OptimizingJob();
			_job.Load(Properties.Settings.Default.CutOptimaConnectionString,
				new Int32[] { detailsIistID });
			_progressForm = new ProgressForm(_job);
			_progressForm.StartPosition = FormStartPosition.CenterParent;
			_progressForm.Cancel += OnCancel;
			_progressForm.Show();

			_job.AsyncExecute();
			while (!_job.Join(100))
			{
				Application.DoEvents();
			}

			_progressForm.Close();

			if (_job.Status == StatusType.Error)
			{
				MessageBox.Show(_job.Error.Message);
			}
			else if (_job.Status == StatusType.Completed)
			{
				ShowCuttingResult(_job.Result);
			}
		}

		private void ShowCuttingResult(List<CuttingScheme> result)
		{
			CuttingResultForm form = new CuttingResultForm();
			form.MdiParent = MainForm.Instance;
			form.DataSource = result;
			form.Show();
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
				_progressForm = new ProgressForm(_job);
				_progressForm.StartPosition = FormStartPosition.CenterParent;
				_progressForm.Cancel += OnCancel;
				_progressForm.Show();

				_job.AsyncExecute();
				while (!_job.Join(500))
				{
					Application.DoEvents();
				}

				if (_job.Status == StatusType.Error)
				{
					MessageBox.Show(_job.Error.Message);					
				}
				else if (_job.Status == StatusType.Completed)
				{
					ShowCuttingResult(_job.Result);
				}
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

        internal void Stub()
        {
            CuttingResultForm form = new CuttingResultForm();
            List<CuttingScheme> schemes = new List<CuttingScheme>();
            CuttingScheme scheme = new CuttingScheme();
            scheme.Height = 1200;
            scheme.Width = 2100;
            scheme.Material = new Material(1, "ЛДСП Белая", true);
            scheme.Parameters = new ParametersCollection();
            scheme.Parameters.CutterThickness = 4;
            Section remain;
            scheme.Cut(scheme.RootSection, 500, CutType.Vertical, out remain);
            Section remain2;
            scheme.Cut(remain, 550, CutType.Horizontal, out remain2);
            schemes.Add((CuttingScheme)scheme.Clone());
            form.DataSource = schemes;
            form.MdiParent = MainForm.Instance;
            form.Show();
        }
    }
}
