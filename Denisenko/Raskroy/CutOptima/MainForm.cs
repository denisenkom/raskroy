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
		}

		private void detailsListsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OpenListsEditor();
		}

		private void sheetsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OpenSheetsEditor();
		}

		private void materialsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OpenMaterialsEditor();
		}

		private void stdDetailsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			//Mediator.Instance.OpenReferenceDetails();
		}

		private void loadCuttingToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.LoadCuttingCommand();
		}

		private void cuttingParametersToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.OpenCuttingParametersCommand();
		}

		private void optimizeToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.CuttingCommand();
		}

		private void exitMenuItem_Click(object sender, EventArgs e)
		{
			Close();
		}

		private void MainForm_Load(object sender, EventArgs e)
		{
			Mediator.Instance.Startup();
		}

		private void baseSelectionToolStripMenuItem_Click(object sender, EventArgs e)
		{
			DBManager.Instance.SelectDB(this);
		}
	}
}