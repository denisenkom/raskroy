using System;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.Text;

using Denisenko.Cutting;

namespace CuttingOptimizerTester
{
	public class XmlPart
	{
		[XmlAttribute("name")]
		public String Name;
		[XmlAttribute("sizeA")]
		public Decimal SizeA;
		[XmlAttribute("sizeB")]
		public Decimal SizeB;
		[XmlAttribute("amount")]
		public Int32 Amount;

		public Part Convert()
		{
			Part part = new Part();
			part.Length = SizeA;
			part.Width = SizeB;
			part.Quantity = Amount;
			return part;
		}
	}
}
