using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;
using Denisenko;
using Denisenko.Cutting;
using Denisenko.Cutting.Optimizing;
using Denisenko.Cutting.Converting;

namespace CuttingOptimizerTester
{
	class Program
	{
		static Optimizer optimizer = new Optimizer();
		static LC4Convertor convertor = new LC4Convertor();

		static void Test1()
		{
			Part part = new Part();
			part.Length = 200M;
			part.Width = 200M;
			part.Quantity = 1;
			part.CanRotate = false;
			optimizer.Parts.Add(part);

			Sheet sheet = new Sheet();
			sheet.Width = 324M;
			sheet.Height = 324M;
			sheet.Thickness = 16M;
			optimizer.Sheets.Add(sheet);

			optimizer.Parameters.CutterThickness = 10M;
			while (optimizer.NextResult())
			{
				//schemes.Add(optimizer.CurrentResult);
			}
		}

		static void Test2()
		{
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
			while (optimizer.NextResult())
			{
				//schemes.Add(optimizer.CurrentResult);
			}
		}

		static void Test3()
		{
			Part part = new Part();
			part.Length = 400M;
			part.Width = 400M;
			part.Quantity = 4;
			part.CanRotate = true;
			optimizer.Parts.Add(part);

			Sheet sheet = new Sheet();
			sheet.Width = 1024M;
			sheet.Height = 1024M;
			sheet.Thickness = 16M;
			optimizer.Sheets.Add(sheet);

			optimizer.Parameters.CutterThickness = 10M;
			while (optimizer.NextResult())
			{
				//schemes.Add(optimizer.CurrentResult);
			}
		}

		static void Test4()
		{
			Part part = new Part();
			part.Length = 400M;
			part.Width = 200M;
			part.Quantity = 8;
			part.CanRotate = true;
			optimizer.Parts.Add(part);

			Sheet sheet = new Sheet();
			sheet.Width = 1024M;
			sheet.Height = 1024M;
			sheet.Thickness = 16M;
			optimizer.Sheets.Add(sheet);

			optimizer.Parameters.CutterThickness = 10M;
			while (optimizer.NextResult())
			{
				//schemes.Add(optimizer.CurrentResult);
			}
		}

		static void Test5()
		{
			Part part = new Part();
			part.Length = 2383M;
			part.Width = 600M;
			part.Quantity = 2;
			part.CanRotate = true;
			optimizer.Parts.Add(part);

			part = new Part();
			part.Length = 2296M;
			part.Width = 500M;
			part.Quantity = 1;
			part.CanRotate = true;
			optimizer.Parts.Add(part);

			Sheet sheet = new Sheet();
			sheet.Width = 2730M;
			sheet.Height = 1830M;
			sheet.Thickness = 16M;
			optimizer.Sheets.Add(sheet);

			optimizer.Parameters.CutterThickness = 4.4M;
			List<CuttingScheme> schemes = new List<CuttingScheme>();
			while (optimizer.NextResult())
			{
				schemes.Add(optimizer.CurrentResult);
			}
			Denisenko.Cutting.LC4.LC4Document doc = convertor.Convert(schemes);
			doc.InternalName = "SOKOLOV";
			doc.Description = "manually generated";
			doc.Cuttings[0].Name = "00001";
			doc.Serialize(@"SOKOLOV2.xml");
		}

		static void TestXmlData()
		{
			Thread raskroyThread = new Thread(AsyncOptimizing);
			XmlData data = XmlData.Deserialize(@"..\..\testdata.xml");
			foreach (XmlMaterial material in data.Materials)
			{
				optimizer.Sheets.Clear();
				optimizer.Parts.Clear();
				material.Fill(optimizer.Sheets, optimizer.Parts);
				List<CuttingScheme> schemes = new List<CuttingScheme>();
				raskroyThread.Start(schemes);
				while (!raskroyThread.Join(1000))
				{
					Console.Write("..{0}%", optimizer.PercentCompleted);
				}
				Console.WriteLine();
				Console.WriteLine("done");
				Denisenko.Cutting.LC4.LC4Document doc = convertor.Convert(schemes);
				doc.Serialize(@"..\..\result.xml");
			}
		}

		static void AsyncOptimizing(Object param)
		{
			List<CuttingScheme> schemes = (List<CuttingScheme>)param;
			while (optimizer.NextResult())
			{
				schemes.Add(optimizer.CurrentResult);
			}
		}

		static void Main(string[] args)
		{
			TestXmlData();

			/*LC4Convertor convertor = new LC4Convertor();
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
			parser.Save(@"..\..\..\..\Reigenering lc4\converted.lc4", FileMode.Create, doc);*/
		}
	}
}
