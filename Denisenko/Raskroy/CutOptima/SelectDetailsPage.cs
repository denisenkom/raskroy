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
	internal partial class SelectDetailsPage : WizardPage
	{
		private WizDataSet.WizDetailsListsDataTable m_destDetailsList = new WizDataSet.WizDetailsListsDataTable();
        private SelectSheetsPage m_sheetsPage;

		public SelectDetailsPage(SelectSheetsPage sheetsPage)
		{
			InitializeComponent();
            m_sheetsPage = sheetsPage;
            NextClick += OnNextClick;
            destListBox.DataSource = m_destDetailsList;
			destListBox.DisplayMember = "OrderID";
			destListBox.ValueMember = "DetailsListID";
		}

		private void SelectDetailsPage_Load(object sender, EventArgs e)
		{
			detailsListsTableAdapter.Fill(dataSet.WizDetailsLists);
        }

		public WizDataSet.WizDetailsListsDataTable DetailsList
		{
			get { return m_destDetailsList; }
		}

        private WizardPage OnNextClick(WizardPage sender)
        {
            return m_sheetsPage;
        }

		private void CopyRowToTable(WizDataSet.WizDetailsListsRow sourceRow, WizDataSet.WizDetailsListsDataTable destTable)
		{
			WizDataSet.WizDetailsListsRow destRow = destTable.NewWizDetailsListsRow();
			WizDataSet.AssignDetailsListRow(sourceRow, destRow);
			destTable.Rows.Add(destRow);
		}

		private void MoveItems(IList items, WizDataSet.WizDetailsListsDataTable fromTable, WizDataSet.WizDetailsListsDataTable toTable)
		{
			List<DataRow> rowsToRemove = new List<DataRow>();
			foreach (Object x in items)
			{
				CopyRowToTable((WizDataSet.WizDetailsListsRow)((DataRowView)x).Row, toTable);
				rowsToRemove.Add(((DataRowView)x).Row);
			}
			foreach (DataRow row in rowsToRemove)
			{
				fromTable.Rows.Remove(row);
			}
		}
		
		private void issueAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.Items, dataSet.WizDetailsLists, m_destDetailsList);
		}

		private void issueButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.SelectedItems, dataSet.WizDetailsLists, m_destDetailsList);
		}

		private void returnButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.SelectedItems, m_destDetailsList, dataSet.WizDetailsLists);
		}

		private void returnAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.Items, m_destDetailsList, dataSet.WizDetailsLists);
		}

        private void SelectDetailsPage_Activate(WizardPage sender)
        {
            WizardForm.NextAllowed = true;
        }
	}
}
