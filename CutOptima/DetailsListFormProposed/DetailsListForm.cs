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
		private DetailsList _detailsList;

		public DetailsListForm(Int32 detailsListID)
		{
			InitializeComponent();
			_detailsListID = detailsListID;
		}

		public DetailsListForm()
		{
			InitializeComponent();
			_detailsListID = -1;
		}

		private void EndEdit()
		{
			this.Validate();
			/*this.detailsListsBindingSource.EndEdit();
			this.detailsListsDetailsBindingSource.EndEdit();*/
		}

		private void Save()
		{
			/*this.detailsListsTableAdapter.Update(this.dataSet.DetailsLists);
			// binding details
			int detailsListID = dataSet.DetailsLists[0].DetailsListID;
			foreach (DataSet.DetailsListsDetailsRow row in this.dataSet.DetailsListsDetails)
			{
				row.DetailsListID = detailsListID;
			}
			this.detailsListsDetailsTableAdapter.Update(this.dataSet.DetailsListsDetails);*/
		}

		private void detailsListsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			EndEdit();
			Save();
		}

		private void DetailsListForm_Load(object sender, EventArgs e)
		{

			detailsListBindingSource.DataSource = _detailsList;
			this.materialsTableAdapter.Fill(this.dataSet.Materials);
			if (_detailsListID == -1)
			{
				this.dataSet.DetailsLists.AddDetailsListsRow(this.dataSet.DetailsLists.NewDetailsListsRow());
				Text = "Новый список деталей";
			}
			else
			{
				/*this.detailsListsDetailsTableAdapter.FillBy(this.dataSet.DetailsListsDetails, _detailsListID);
				this.detailsListsTableAdapter.FillBy(this.dataSet.DetailsLists, _detailsListID);*/
				Text = "Список деталей - " + ((DataSet.DetailsListsRow)(dataSet.DetailsLists.Rows[0])).OrderID;
			}
		}

		private void optimizeButton_Click(object sender, EventArgs e)
		{
			EndEdit();
			if (dataSet.HasChanges())
			{
				DialogResult result =MessageBox.Show(
					"Прежде чем выполнять раскрой нужно сохранить изменения. " +
					"Сохранить изменения и выполнить раскрой?", "CutOptima", MessageBoxButtons.YesNo,
					MessageBoxIcon.Question);
				if (result == DialogResult.Yes)
				{
					Save();
				}
				else if (result == DialogResult.No)
				{
					return;
				}
			}
			Mediator.Instance.OptimizeDetailsList(_detailsListID);
		}

		private void detailsListsDetailsDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
		{
		}

		private void DetailsListForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			EndEdit();
			if (dataSet.HasChanges())
			{
				DialogResult result = Mediator.Instance.AskUserToSaveChanges();
				if(result == DialogResult.Yes)
				{
					Save();
				}
				else if (result == DialogResult.Cancel)
				{
					e.Cancel = true;
				}
			}
		}

		private void detailsListsDetailsDataGridView_DataError(object sender, DataGridViewDataErrorEventArgs e)
		{
		}

		private void detailDataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
		{
			// Последний введенный материал становится материалом по умолчанию
			/*DataGridViewCell cell = detailsListsDetailsDataGridView[e.ColumnIndex, e.RowIndex];
			DataGridViewColumn column = detailsListsDetailsDataGridView.Columns[e.ColumnIndex];
			if (column.DataPropertyName == "MaterialID")
			{
				dataSet.DetailsListsDetails.MaterialIDColumn.DefaultValue = cell.Value;
			}*/
		}

		private void detailDataGridView_DataError(object sender, DataGridViewDataErrorEventArgs e)
		{
			Mediator.Instance.DataGridView_DataError(sender, e);
		}
	}
}