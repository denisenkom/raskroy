using System;
using System.Globalization;
using System.Collections.Generic;
using System.Text;
using Denisenko;
using Denisenko.Cutting;
using Denisenko.Cutting.Optimizing;
using Denisenko.Cutting.Converting;
using Denisenko.Cutting.LC4;

namespace CuttingOptimizerTester
{
	class Program
	{
		static void Main(string[] args)
		{
			Optimizer optimizer = new Optimizer();
			optimizer.Parts.Add(new Part(Size.Parse("200"), Size.Parse("300"), 3, false));
			optimizer.Sheets.Add(new Sheet(Size.Parse("2730"), Size.Parse("1830")));
			optimizer.Parameters.CutterThickness = Size.Parse("4.4", CultureInfo.InvariantCulture);
			optimizer.Parameters.CutOffBottom = Size.Parse("13");

			LC4Convertor convertor = new LC4Convertor();
			Int32 index = 0;
			while (optimizer.NextResult())
			{
				convertor.AddCuttingResult(optimizer.CurrentResult, index.ToString());
				index++;
			}
			convertor.Result.Save("converted.xml");
		}
	}
}
