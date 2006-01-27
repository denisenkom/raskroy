using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
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
			LC4Document doc = convertor.Result;
			doc.Save("converted.xml");
			doc.InternalName = "converted";
			doc.Generator = "Manualy generated";
			LC4Parser parser = new LC4Parser();
			LC4Sheet sheet = doc.CreateSheet();
			sheet.Size1 = LC4Numeric.FromNonScaled(1000);
			sheet.Size2 = LC4Numeric.FromNonScaled(2000);
			sheet.Thickness = LC4Numeric.FromNonScaled(16);
			doc.Sheets.Add(sheet);
			LC4Variable variable = doc.CreateVariable();
			variable.Name = "Name";
			variable.Value = "Value";
			doc.Cuttings[0].Variables.Add(variable);
			parser.Save(@"..\..\..\..\Reigenering lc4\converted.lc4", FileMode.Create, doc);
		}
	}
}
