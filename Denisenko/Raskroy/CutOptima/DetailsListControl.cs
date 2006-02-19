using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class DetailsListControl : UserControl
	{
		private Parts m_dataSource;

		public Parts DataSource
		{
			get
			{
				return m_dataSource;
			}
			set
			{
				m_dataSource = value;
			}
		}

		public DetailsListControl()
		{
			InitializeComponent();
			PropertyTypes propTypes = Mediator.Instance.PropertyTypes;
			foreach (PropertyType propType in propTypes)
			{
				Int32 i = dataGridView.Columns.Add(propType.Id, propType.Description);
				DataGridViewColumn column = dataGridView.Columns[i];
				column.DataPropertyName = propType.Id;
			}
		}
	}
}
