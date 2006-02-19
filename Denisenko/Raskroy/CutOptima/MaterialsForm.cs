using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class MaterialsForm : Form
	{
		public MaterialsForm()
		{
			InitializeComponent();
		}

		private void materialsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.materialsBindingSource.EndEdit();
			this.materialsTableAdapter.Update(this.dataSet.Materials);

		}

		private void MaterialsForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.Materials' table. You can move, or remove it, as needed.
			this.materialsTableAdapter.Fill(this.dataSet.Materials);

		}
	}
}