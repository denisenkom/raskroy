using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Text;
using System.Windows.Forms;
using Denisenko.Cutting;
using Denisenko.Cutting.Optimizing;
using Denisenko.Cutting.Converting;
using Denisenko.Cutting.LC4;

namespace Denisenko.Cutting.CutOptima
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
		{

		}

		private void optimizeButton_Click(object sender, EventArgs e)
		{
			/*Optimizer optimizer = new Optimizer();
			foreach(DataSet.DetailsRow row in dataSet.Details.Rows)
			{
				optimizer.Parts.Add(new Part(
					Denisenko.Size.Parse(row.Length),
					Denisenko.Size.Parse(row.Width),
					row.Quantity,
					false)
				);
			}
			optimizer.Parts.Add
			optimizer.Sheets.Add(new Sheet(new Denisenko.Size(1800.0),
				new Denisenko.Size(1200.0)));*/
			Optimizer optimizer = new Optimizer();
			optimizer.Parts.Add(new Part(Denisenko.Size.Parse("433"), Denisenko.Size.Parse("300"), 4, false));
			optimizer.Parts.Add(new Part(Denisenko.Size.Parse("2240"), Denisenko.Size.Parse("798"), 2, false));
			optimizer.Parts.Add(new Part(Denisenko.Size.Parse("1566"), Denisenko.Size.Parse("70"), 1, false));
			optimizer.Parts.Add(new Part(Denisenko.Size.Parse("530"), Denisenko.Size.Parse("70"), 2, false));
			optimizer.Sheets.Add(new Sheet(Denisenko.Size.Parse("2710"), Denisenko.Size.Parse("1830")));
			optimizer.Parameters.CutterThickness = Denisenko.Size.Parse("4.4", CultureInfo.InvariantCulture);
			optimizer.Parameters.CutOffBottom = Denisenko.Size.Parse("13");

			LC4Convertor lc4Convertor = new LC4Convertor();
			Int32 index = 0;
			while (optimizer.NextResult())
			{
				lc4Convertor.AddCuttingResult(optimizer.CurrentResult, index.ToString());
				cuttingControl.DataSource = optimizer.CurrentResult;
				index++;
			}
			lc4Convertor.Result.Save("result.xml");
		}
	}
}