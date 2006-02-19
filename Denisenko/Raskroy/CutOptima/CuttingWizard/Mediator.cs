using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima.CuttingWizard
{
	class Mediator
	{
		private BaseWizardForm m_wizardForm;
		private Boolean m_finished;
		private Int32[] m_detailsListsIDs;
		private Int32[] m_sheetsIDs;

		public Mediator()
		{
			m_wizardForm = new BaseWizardForm(this);
			m_finished = false;
		}

		public Boolean NextAllowed
		{
			get
			{
				return m_wizardForm.NextAllowed;
			}
			set
			{
				m_wizardForm.NextAllowed = value;
			}
		}

		public void Finish()
		{
			SelectDetailsPage detailsPage = (SelectDetailsPage)m_wizardForm.GetPage(0);
			m_detailsListsIDs = new Int32[detailsPage.DetailsList.Rows.Count];
			Int32 i = 0;
			foreach (DataSet.DetailsListsRow row in detailsPage.DetailsList.Rows)
			{
				m_detailsListsIDs[i] = row.DetailsListID;
				i++;
			}

			SelectSheetsPage sheetsPage = (SelectSheetsPage)m_wizardForm.GetPage(1);
			m_sheetsIDs = new Int32[sheetsPage.SheetsList.Rows.Count];
			i = 0;
			foreach (DataSet.SheetsRow row in sheetsPage.SheetsList.Rows)
			{
				m_sheetsIDs[i] = row.SheetID;
				i++;
			}

			m_wizardForm.Close();

			m_finished = true;
		}

		public Boolean Finished { get { return m_finished; } }
		public Int32[] DetailsListsIDs { get { return m_detailsListsIDs; } }
		public Int32[] SheetsIDs { get { return m_sheetsIDs; } }

		internal void Execute(IWin32Window owner)
		{
			m_wizardForm.ShowDialog(owner);
		}
	}
}
