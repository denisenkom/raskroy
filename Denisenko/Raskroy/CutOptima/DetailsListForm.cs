using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class DetailsListForm : Form
	{
		public DetailsListForm()
		{
			InitializeComponent();
		}

		private void DetailsListForm_Load(object sender, EventArgs e)
		{
			// TODO: This line of code loads data into the 'dataSet.DetailsListsContents' table. You can move, or remove it, as needed.
			this.detailsListsContentsTableAdapter.Fill(this.dataSet.DetailsListsContents);
			// TODO: This line of code loads data into the 'dataSet.DetailsLists' table. You can move, or remove it, as needed.
			this.detailsListsTableAdapter.Fill(this.dataSet.DetailsLists);

		}
	}
}