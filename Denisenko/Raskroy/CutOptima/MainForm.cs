using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class MainForm : Form
	{
		private MainForm()
		{
			InitializeComponent();
		}

		private static MainForm m_instance;

		public static MainForm Instance
		{
			get
			{
				if (m_instance == null)
					m_instance = new MainForm();
				return m_instance;
			}
		}

		private void referenceDetailsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OpenReferenceDetails();
		}

		private void detailsListsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OpenListsEditor();
		}
	}
}