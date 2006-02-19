using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class DetailsListsForm : Form
	{
		public DetailsListsForm()
		{
			InitializeComponent();
		}

		private void detailsListsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.detailsListsBindingSource.EndEdit();
			this.detailsListsTableAdapter.Update(this.dataSet.DetailsLists);

		}

		private void DetailsListsForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.DetailsLists' table. You can move, or remove it, as needed.
			this.detailsListsTableAdapter.Fill(this.dataSet.DetailsLists);

		}

		private void detailsListsDataGridView_DoubleClick(object sender, EventArgs e)
		{
			DataRowView dataRowView = (DataRowView)detailsListsDataGridView.CurrentRow.DataBoundItem;
			DataSet.DetailsListsRow row = (DataSet.DetailsListsRow)dataRowView.Row;
			Mediator.Instance.OpenListEditor(row.DetailsListID);
		}
	}
}