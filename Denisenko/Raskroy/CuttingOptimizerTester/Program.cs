using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using Denisenko;
using Denisenko.Cutting;
using Denisenko.Cutting.Optimizing;
using Denisenko.Cutting.Converting;

namespace CuttingOptimizerTester
{
	class Program
	{
		static void Main(string[] args)
		{
			Optimizer optimizer = new Optimizer();

			Part part = new Part();
			part.Length = 200M;
			part.Width = 200M;
			part.Quantity = 3;
			part.CanRotate = false;
			optimizer.Parts.Add(part);

			Sheet sheet = new Sheet();
			sheet.Width = 2730M;
			sheet.Height = 1830M;
			sheet.Thickness = 16M;
			optimizer.Sheets.Add(sheet);

			optimizer.Parameters.CutterThickness = 4.4M;
			optimizer.Parameters.CutOffBottom = 13M;

			LC4Convertor convertor = new LC4Convertor();
			List<CuttingScheme> schemes = new List<CuttingScheme>();
			while (optimizer.NextResult())
			{
				schemes.Add(optimizer.CurrentResult);
			}
			Denisenko.Cutting.LC4.LC4Document doc = convertor.Convert(schemes);
			doc.Serialize("converted.xml");
			doc.InternalName = "converted";
			doc.Description = "Manualy generated";
			Denisenko.Cutting.LC4.LC4Parser parser = new Denisenko.Cutting.LC4.LC4Parser();
			parser.Save(@"..\..\..\..\Reigenering lc4\converted.lc4", FileMode.Create, doc);
		}
	}
}
