using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public class LC4Sheet
	{
		[XmlAttribute("size1")]
		public Decimal Size1;

		[XmlAttribute("size2")]
		public Decimal Size2;

		[XmlAttribute("thickness")]
		public Decimal Thickness;

		[XmlAttribute("someString1")]
		public String SomeString1;

		[XmlAttribute("someString2")]
		public String SomeString2;

		[XmlAttribute("someString3")]
		public String SomeString3;

		[XmlAttribute("someInteger1")]
		public Int32 SomeInteger1;

		[XmlAttribute("someInteger2")]
		public Int32 SomeInteger2;

		[XmlAttribute("someInteger3")]
		public Int32 SomeInteger3;

		[XmlAttribute("someInteger4")]
		public Int32 SomeInteger4;

		public LC4Sheet()
		{
			SomeInteger1 = 1;
			SomeInteger2 = 0; // may be 1, 3, 4, 7, 31. Can it be bit flags? Correlate with LC4Cutting.SomeInteger9 and SomeInteger12.
			SomeInteger3 = 0;
			SomeInteger4 = 0;
			SomeString1 = "";
			SomeString2 = "";
			SomeString3 = "";
		}
	}
}
