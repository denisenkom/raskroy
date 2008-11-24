using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	internal partial class SelectSheetsPage : WizardPage
	{
		private WizDataSet.WizSheetsDataTable m_destSheetsList = new WizDataSet.WizSheetsDataTable();
        private bool m_finishAllowed = false;

        public SelectSheetsPage()
		{
			InitializeComponent();
            destListBox.DataSource = m_destSheetsList;
			destListBox.DisplayMember = "Name";
			destListBox.ValueMember = "SheetID";
		}

		private void SelectSheetsPage_Load(object sender, EventArgs e)
		{
			sheetsTableAdapter.Fill(dataSet.WizSheets);
			MoveItems(sourceListBox.Items, dataSet.WizSheets, m_destSheetsList);
		}

		public WizDataSet.WizSheetsDataTable SheetsList { get { return m_destSheetsList; } }

		private void CopyRowToTable(DataRow sourceRow, DataTable destTable)
		{
			DataRow destRow = destTable.NewRow();
			for (Int32 i = 0; i < sourceRow.ItemArray.Length; i++)
			{
				destRow[i] = sourceRow[i];
			}
			destTable.Rows.Add(destRow);
		}

		private void MoveItems(IList items, DataTable fromTable, DataTable toTable)
		{
			List<DataRow> rowsToRemove = new List<DataRow>();
			foreach (Object x in items)
			{
				CopyRowToTable(((DataRowView)x).Row, toTable);
				rowsToRemove.Add(((DataRowView)x).Row);
			}
			foreach (DataRow row in rowsToRemove)
			{
				fromTable.Rows.Remove(row);
			}
		}

		private void issueAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.Items, dataSet.WizSheets, m_destSheetsList);
            WizardForm.FinishAllowed = m_finishAllowed = true;
		}

		private void issueButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.SelectedItems, dataSet.WizSheets, m_destSheetsList);
            WizardForm.FinishAllowed = m_finishAllowed = true;
		}

		private void returnButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.SelectedItems, m_destSheetsList, dataSet.WizSheets);
            WizardForm.FinishAllowed = m_finishAllowed = destListBox.Items.Count > 0;
		}

		private void returnAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.Items, m_destSheetsList, dataSet.WizSheets);
            WizardForm.FinishAllowed = m_finishAllowed = false;
		}

        private void SelectSheetsPage_Activate(WizardPage sender)
        {
            WizardForm.FinishAllowed = m_finishAllowed;
        }
	}
}
