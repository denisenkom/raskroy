using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class ReferenceDetailsForm : Form
	{
		private ReferenceDetailsForm()
		{
			InitializeComponent();
		}

		private void referenceDetailsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.referenceDetailsBindingSource.EndEdit();
			this.referenceDetailsTableAdapter.Update(this.dataSet.ReferenceDetails);

		}

		private void ReferenceDetailsForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.ReferenceDetails' table. You can move, or remove it, as needed.
			this.referenceDetailsTableAdapter.Fill(this.dataSet.ReferenceDetails);

		}

		private static ReferenceDetailsForm m_instance;

		public static ReferenceDetailsForm Instance
		{
			get
			{
				if (m_instance == null)
					m_instance = new ReferenceDetailsForm();
				return m_instance;
			}
		}
	}
}