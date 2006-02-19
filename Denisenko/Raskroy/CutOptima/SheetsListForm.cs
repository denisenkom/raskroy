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

		private void sheetsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.sheetsBindingSource.EndEdit();
			this.sheetsTableAdapter.Update(this.dataSet.Sheets);

		}

		private void sheetsDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
		{

		}
	}
}