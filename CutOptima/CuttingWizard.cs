using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	class CuttingWizard
	{
        private WizardForm m_wizard;
        private SelectSheetsPage m_sheetsPage;
        private SelectDetailsPage m_detailsPage;
        private Int32[] m_detailsListsIDs;
        private Int32[] m_sheetsIDs;

		public CuttingWizard()
		{
            m_sheetsPage = new SelectSheetsPage();
            m_detailsPage = new SelectDetailsPage(m_sheetsPage);
            m_wizard = new WizardForm(m_detailsPage);
            m_wizard.Text = "Оптимизация";
		}

		internal Boolean Execute(IWin32Window owner)
		{
            m_wizard.ShowDialog(owner);
            if (m_wizard.Finished)
            {
                m_detailsListsIDs = new Int32[m_detailsPage.DetailsList.Rows.Count];
                Int32 i = 0;
                foreach (WizDataSet.WizDetailsListsRow row in m_detailsPage.DetailsList.Rows)
                {
                    m_detailsListsIDs[i] = row.DetailsListID;
                    i++;
                }

                m_sheetsIDs = new Int32[m_sheetsPage.SheetsList.Rows.Count];
                i = 0;
                foreach (WizDataSet.WizSheetsRow row in m_sheetsPage.SheetsList.Rows)
                {
                    m_sheetsIDs[i] = row.SheetID;
                    i++;
                }
            }
            return m_wizard.Finished;
		}

        public Int32[] DetailsListsIDs { get { return m_detailsListsIDs; } }
        public Int32[] SheetsIDs { get { return m_sheetsIDs; } }
	}
}
