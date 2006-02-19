using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class DetailsListForm : Form
	{
		private Int32 _detailsListID;

		public DetailsListForm(Int32 detailsListID)
		{
			InitializeComponent();
			_detailsListID = detailsListID;
		}

		private void detailsListsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.detailsListsBindingSource.EndEdit();
			this.detailsListsDetailsBindingSource.EndEdit();
			this.detailsListsTableAdapter.Update(this.dataSet.DetailsLists);
			this.detailsListsDetailsTableAdapter.Update(this.dataSet.DetailsListsDetails);
		}

		private void DetailsListForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.Materials' table. You can move, or remove it, as needed.
			this.materialsTableAdapter.Fill(this.dataSet.Materials);
			// TODO: This line of code loads data into the 'dataSet.DetailsListsDetails' table. You can move, or remove it, as needed.
			this.detailsListsDetailsTableAdapter.FillBy(this.dataSet.DetailsListsDetails, _detailsListID);
			// TODO: This line of code loads data into the 'dataSet.DetailsLists' table. You can move, or remove it, as needed.
			this.detailsListsTableAdapter.FillBy(this.dataSet.DetailsLists, _detailsListID);
			Text = "Список деталей - " + ((DataSet.DetailsListsRow)(dataSet.DetailsLists.Rows[0])).OrderID;
		}

		private void optimizeButton_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OptimizeDetailsList(_detailsListID);
		}

		private void detailsListsDetailsDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
		{
			// Последний введенный материал становится материалом по умолчанию
			DataGridViewCell cell = detailsListsDetailsDataGridView[e.ColumnIndex, e.RowIndex];
			DataGridViewColumn column = detailsListsDetailsDataGridView.Columns[e.ColumnIndex];
			if (dataSet.DetailsListsDetails.Columns[column.DataPropertyName] == dataSet.DetailsListsDetails.MaterialIDColumn)
			{
				dataSet.DetailsListsDetails.MaterialIDColumn.DefaultValue = cell.Value;
			}
		}
	}
}