using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class PartPropertiesForm : Form
	{
		public PartPropertiesForm()
		{
			InitializeComponent();
		}

		private void partPropertiesBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			Save();
		}

		private void Save()
		{
			this.Validate();
			this.partPropertiesBindingSource.EndEdit();
			this.partPropertiesTableAdapter.Update(this.dataSet.PartProperties);
		}

		private void PartPropertiesForm_Load(object sender, EventArgs e)
		{
			this.partPropertiesTableAdapter.Fill(this.dataSet.PartProperties);
		}

		private void PartPropertiesForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			DataTable changes = this.dataSet.PartProperties.GetChanges();
			if (changes != null)
			{
				if (MessageBox.Show(this, "Список свойств изменен. Сохранить изменения?", "CutOptima", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) == DialogResult.Yes)
				{
					Save();
				}
			}
		}
	}
}