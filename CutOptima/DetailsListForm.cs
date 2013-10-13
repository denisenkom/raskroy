using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public enum DetailsListOpenType
	{
		Open,
		AddNew,
	}

	public partial class DetailsListForm : Form
	{
		private Int32 _detailsListID;
		private DetailsListOpenType _openType;

		public DetailsListForm(DetailsListOpenType openType)
		{
			_openType = openType;
			_detailsListID = -1;
			InitializeComponent();
		}

		public DetailsListForm(DetailsListOpenType openType, Int32 detailsListID)
		{
			_openType = openType;
			_detailsListID = detailsListID;
			InitializeComponent();
		}

		private void detailsListsBindingNavigatorSaveItem_Click(
			object sender, EventArgs e)
		{
			EndEdit();
			Save();
		}

		private void DetailsListForm_Load(object sender, EventArgs e)
		{
			this.materialsTableAdapter.Fill(this.dataSet.Materials);
			if (_openType == DetailsListOpenType.Open)
			{
				this.detailsListsTableAdapter.FillBy(this.dataSet.DetailsLists,
					_detailsListID);

				this.detailsListsDetailsTableAdapter.FillBy(
					this.dataSet.DetailsListsDetails, _detailsListID);

				Text = "Список деталей - " + ((DataSet.DetailsListsRow)
					(dataSet.DetailsLists.Rows[0])).OrderID;
			}
			else if (_openType == DetailsListOpenType.AddNew)
			{
				this.detailsListsBindingSource.AddNew();
				Text = "Новый список деталей";
			}
		}

		private void optimizeButton_Click(object sender, EventArgs e)
		{
			EndEdit();
			if (dataSet.HasChanges())
			{
				DialogResult result = MessageBox.Show(
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

		private void detailsListsDetailsDataGridView_CellEndEdit(object sender,
			DataGridViewCellEventArgs e)
		{
			// Последний введенный материал становится материалом по умолчанию
			DataGridViewCell cell = detailsListsDetailsDataGridView
				[e.ColumnIndex, e.RowIndex];
			DataGridViewColumn column = detailsListsDetailsDataGridView.Columns
				[e.ColumnIndex];

			if (dataSet.DetailsListsDetails.Columns[column.DataPropertyName] ==
				dataSet.DetailsListsDetails.MaterialIDColumn)
			{
				dataSet.DetailsListsDetails.MaterialIDColumn.DefaultValue = cell.Value;
			}
		}

		private void detailsListsDetailsDataGridView_Enter(object sender, EventArgs e)
		{
			detailsListsBindingSource.EndEdit();
		}

		private void EndEdit()
		{
			Validate();
			detailsListsBindingSource.EndEdit();
			detailsListsDetailsBindingSource.EndEdit();
		}

		private void Save()
		{
			detailsListsTableAdapter.Update(dataSet.DetailsLists.Select("", "",
				DataViewRowState.Added | DataViewRowState.ModifiedCurrent));
			detailsListsDetailsTableAdapter.Update(dataSet.DetailsListsDetails);
			detailsListsTableAdapter.Update(dataSet.DetailsLists.Select("", "",
				DataViewRowState.Deleted));
		}

		private void DetailsListForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			EndEdit();
			if (dataSet.HasChanges())
			{
				DialogResult result = Mediator.Instance.AskUserToSaveChanges();
				if (result == DialogResult.Yes)
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
			Mediator.Instance.DataGridView_DataError(sender, e);
		}

        private void detailsListsDetailsDataGridView_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Control && e.KeyCode == Keys.C)
            {
                DataObject d = detailsListsDetailsDataGridView.GetClipboardContent();
                Clipboard.SetDataObject(d);
                e.Handled = true;
            }
            else if (e.Control && e.KeyCode == Keys.V)
            {
                string s = Clipboard.GetText();
                string[] lines = s.Split('\n');
                int row = detailsListsDetailsDataGridView.CurrentCell.RowIndex;
                int col = detailsListsDetailsDataGridView.CurrentCell.ColumnIndex;
                foreach (string line in lines)
                {
                    try
                    {
                        if (row >= detailsListsDetailsDataGridView.RowCount)
                        {
                            break;
                        }
                        string[] cells = line.Split('\t');
                        for (int i = 0; i < cells.GetLength(0); ++i)
                        {
                            if (col + i < this.detailsListsDetailsDataGridView.ColumnCount)
                            {
                                detailsListsDetailsDataGridView[col + i, row].Value = Convert.ChangeType(cells[i], detailsListsDetailsDataGridView[col + i, row].ValueType);
                            }
                            else
                            {
                                break;
                            }
                        }
                        row++;
                        detailsListsDetailsBindingSource.AddNew();
                    }
                    catch (Exception)
                    {
                        break;
                    }
                }
            }
        }
	}
}