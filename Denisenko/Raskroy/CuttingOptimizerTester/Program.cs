using System;
using System.Collections.Generic;
using System.Text;
using Denisenko.Cutting;
using Denisenko.Cutting.Optimizing;
using Denisenko.Cutting.Converting;
using Denisenko.LC4Parser;

namespace CuttingOptimizerTester
{
	class Program
	{
		static void Main(string[] args)
		{
			Optimizer optimizer = new Optimizer();
			optimizer.Parts.Add(new Part(200, 300, 3, false));
			optimizer.Sheets.Add(new Sheet(2730, 1830));
			optimizer.Parameters.CutterThickness = 4;
			optimizer.Parameters.CutOffBottom = 13;

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
