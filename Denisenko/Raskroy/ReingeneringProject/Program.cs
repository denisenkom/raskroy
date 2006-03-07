using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Denisenko.Cutting.LC4;

namespace ReingeneringProject
{
	class Program
	{
		static void Main(string[] args)
		{
			LC4Parser parser = new LC4Parser();
			LC4Document doc = parser.Load(@"..\..\export.LC4");
			parser.Save(@"..\..\1loadsave.lc4", FileMode.Create, doc); // pass
			doc.Serialize(@"..\..\1loadsave.xml");

			doc.Cuttings.RemoveRange(1, doc.Cuttings.Count - 1);
			parser.Save(@"..\..\2singleCutting.lc4", FileMode.Create, doc);
			doc.Serialize(@"..\..\2singleCutting.xml");

			doc.Sheets.RemoveRange(1, doc.Sheets.Count - 1);
			parser.Save(@"..\..\3singleSheet.lc4", FileMode.Create, doc);
			doc.Serialize(@"..\..\3singleSheet.xml");

			doc.Cuttings[0].Variables.Clear();
			parser.Save(@"..\..\4noVariables.lc4", FileMode.Create, doc);
			doc.Serialize(@"..\..\4noVariables.xml");

			doc.Description = "Other name";
			parser.Save(@"..\..\5otherGen.lc4", FileMode.Create, doc);
			doc.Serialize(@"..\..\5otherGen.xml");
		}
	}
}
