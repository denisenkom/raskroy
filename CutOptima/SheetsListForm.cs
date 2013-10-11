using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class SheetsListForm : Form
	{
		public SheetsListForm()
		{
			InitializeComponent();
		}

		private void SheetsListForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.Materials' table. You can move, or remove it, as needed.
			this.materialsTableAdapter.Fill(this.dataSet.Materials);
			// TODO: This line of code loads data into the 'dataSet.Sheets' table. You can move, or remove it, as needed.
			this.sheetsTableAdapter.Fill(this.dataSet.Sheets);

		}

		private void EndEdit()
		{
			this.Validate();
			this.sheetsBindingSource.EndEdit();
		}

		private void Save()
		{
			this.sheetsTableAdapter.Update(this.dataSet.Sheets);
		}

		private void sheetsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			EndEdit();
			Save();
		}

		private void SheetsListForm_FormClosing(object sender, FormClosingEventArgs e)
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

		private void sheetsDataGridView_DataError(object sender, DataGridViewDataErrorEventArgs e)
		{
			Mediator.Instance.DataGridView_DataError(sender, e);
		}
	}
}