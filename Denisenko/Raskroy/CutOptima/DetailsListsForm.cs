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
		private static DetailsListsForm m_instance;

		public static DetailsListsForm Instance
		{
			get
			{
				if (m_instance == null)
					m_instance = new DetailsListsForm();
				return m_instance;
			}
		}

		private DetailsListsForm()
		{
			InitializeComponent();
		}

		private void listBox_DoubleClick(object sender, EventArgs e)
		{
			Mediator.Instance.OpenListEditor(((DataSet.DetailsListsRow)((DataRowView)listBox.SelectedItem).Row).DetailsListID);
		}

		private void DetailsListsForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.DetailsLists' table. You can move, or remove it, as needed.
			this.detailsListsTableAdapter.Fill(this.dataSet.DetailsLists);
		}
	}
}