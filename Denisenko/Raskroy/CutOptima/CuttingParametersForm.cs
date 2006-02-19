using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class CuttingParametersForm : Form
	{
		public CuttingParametersForm()
		{
			InitializeComponent();
		}

		private void cuttingParametersBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.cuttingParametersBindingSource.EndEdit();
			this.cuttingParametersTableAdapter.Update(this.dataSet.CuttingParameters);

		}

		private void CuttingParametersForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.CuttingParameters' table. You can move, or remove it, as needed.
			this.cuttingParametersTableAdapter.Fill(this.dataSet.CuttingParameters);

		}
	}
}