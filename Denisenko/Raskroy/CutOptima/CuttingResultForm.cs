using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Runtime.Serialization.Formatters;
using System.Runtime.Serialization.Formatters.Binary;

using Denisenko.Cutting.CutOptima.DataSetTableAdapters;

namespace Denisenko.Cutting.CutOptima
{
	public partial class CuttingResultForm : Form
	{
		private List<CuttingScheme> m_dataSource;

		public CuttingResultForm()
		{
			InitializeComponent();
		}

		public List<CuttingScheme> DataSource
		{
			get
			{
				return m_dataSource;
			}
			set
			{
				m_dataSource = value;
				tabControl.TabPages.Clear();
				Int32 index = 0;
				foreach (CuttingScheme scheme in value)
				{
					TabPage tabPage = new TabPage((index + 1).ToString());

					Label label = new Label();
					label.Text = String.Format("Схема: {0}  разм.: {1:0.0} x {2:0.0}  группа мат.: {3}", index + 1, scheme.Width, scheme.Height, scheme.Material.Name);
					label.Dock = DockStyle.Top;

					CuttingControl cuttingControl = new CuttingControl();
					cuttingControl.DataSource = scheme;
					cuttingControl.Dock = DockStyle.Fill;

					tabPage.Controls.Add(label);
					tabPage.Controls.Add(cuttingControl);
					tabControl.TabPages.Add(tabPage);
					index++;
				}
			}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.SaveCuttingCommand(DataSource);
		}

		private void exportLC4ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.ExportLC4Command(DataSource);
		}
	}
}