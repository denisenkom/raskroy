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
	internal partial class SelectSheetsPage : BasePage
	{
		private DataSet.SheetsDataTable m_destSheetsList = new DataSet.SheetsDataTable();

		public SelectSheetsPage(Mediator mediator)
			: base(mediator)
		{
			InitializeComponent();
			destListBox.DataSource = m_destSheetsList;
			destListBox.DisplayMember = "Name";
			destListBox.ValueMember = "SheetID";
		}

		private void SelectSheetsPage_Load(object sender, EventArgs e)
		{
			sheetsTableAdapter.Fill(dataSet.Sheets);
			MoveItems(sourceListBox.Items, dataSet.Sheets, m_destSheetsList);
		}

		public override String Description
		{
			get { return "Выберите листы на которых нужно разложить детали."; }
		}

		public DataSet.SheetsDataTable SheetsList { get { return m_destSheetsList; } }

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
			MoveItems(sourceListBox.Items, dataSet.Sheets, m_destSheetsList);
			m_mediator.NextAllowed = true;
		}

		private void issueButton_Click(object sender, EventArgs e)
		{
			MoveItems(sourceListBox.SelectedItems, dataSet.Sheets, m_destSheetsList);
			m_mediator.NextAllowed = true;
		}

		private void returnButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.SelectedItems, m_destSheetsList, dataSet.Sheets);
			m_mediator.NextAllowed = destListBox.Items.Count > 0;
		}

		private void returnAllButton_Click(object sender, EventArgs e)
		{
			MoveItems(destListBox.Items, m_destSheetsList, dataSet.Sheets);
			m_mediator.NextAllowed = false;
		}
	}
}
