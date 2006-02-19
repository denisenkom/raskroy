using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima.CuttingWizard
{
	internal partial class SelectDetailsPage : BasePage
	{
		private DataSet.DetailsListsDataTable m_destDetailsList = new DataSet.DetailsListsDataTable();

		public SelectDetailsPage(Mediator mediator)
			: base(mediator)
		{
			InitializeComponent();
			destListBox.DataSource = m_destDetailsList;
			destListBox.DisplayMember = "OrderID";
			destListBox.ValueMember = "DetailsListID";
		}

		private void SelectDetailsPage_Load(object sender, EventArgs e)
		{
			detailsListsTableAdapter.Fill(dataSet.DetailsLists);
		}

		public override String Description
		{
			get { return "Выберите списки деталей, которые нужно разложить."; }
		}

		public DataSet.DetailsListsDataTable DetailsList
		{
			get { return m_destDetailsList; }
		}

		private void CopyRowToTable(DataSet.DetailsListsRow sourceRow, DataSet.DetailsListsDataTable destTable)
		{
			DataSet.DetailsListsRow destRow = destTable.NewDetailsListsRow();
			DataSet.AssignDetailsListRow(sourceRow, destRow);
			destTable.Rows.Add(destRow);
		}

		private void MoveItems(IList items, DataSet.DetailsListsDataTable fromTable, DataSet.DetailsListsDataTable toTable)
		{
			List<DataRow> rowsToRemove = new List<DataRow>();
			foreach (Object x in items)
			{
				CopyRowToTable((DataSet.DetailsListsRow)((DataRowView)x).Row, toTable);
				rowsToRemove.Add(((DataRowView)x).Row);
			}
			foreach (DataRow row in rowsToRemove)
			{
				fromTable.Rows.Remove(row);
			}
		}
		
		private void issueAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.Items, dataSet.DetailsLists, m_destDetailsList);
		}

		private void issueButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.SelectedItems, dataSet.DetailsLists, m_destDetailsList);
		}

		private void returnButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.SelectedItems, m_destDetailsList, dataSet.DetailsLists);
		}

		private void returnAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.Items, m_destDetailsList, dataSet.DetailsLists);
		}
	}
}
