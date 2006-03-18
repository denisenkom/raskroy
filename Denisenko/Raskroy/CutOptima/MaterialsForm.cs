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

		private void EndEdit()
		{
			this.Validate();
			this.materialsBindingSource.EndEdit();
		}

		private void Save()
		{
			this.materialsTableAdapter.Update(this.dataSet.Materials);
		}

		private void materialsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			EndEdit();
			Save();
		}

		private void MaterialsForm_Load(object sender, EventArgs e)
		{
			this.materialsTableAdapter.Fill(this.dataSet.Materials);
		}

		private void MaterialsForm_FormClosing(object sender, FormClosingEventArgs e)
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
	}
}