using System;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.Text;

using Denisenko.Cutting;

namespace CuttingOptimizerTester
{
	public class XmlSheet
	{
		[XmlAttribute("name")]
		public String Name;
		[XmlAttribute("sizeA")]
		public Decimal SizeA;
		[XmlAttribute("sizeB")]
		public Decimal SizeB;
		[XmlAttribute("Thickness")]
		public Decimal Thickness;

		public Sheet Convert()
		{
			Sheet result = new Sheet();
			result.Width = SizeB;
			result.Height = SizeA;
			result.Thickness = Thickness;
			return result;
		}
	}
}
