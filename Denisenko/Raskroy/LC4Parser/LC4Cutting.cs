using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public class LC4Cutting
	{
		[XmlAttribute("name")]
		public String Name;

		/*
		 * Размер стороны, параллельно к которой идет первое пиление
		 */
		[XmlAttribute("size1")]
		public Decimal Size1;

		/*
		 * Размер стороны, перпендикулярно к которой идет первое пиление
		 */
		[XmlAttribute("size2")]
		public Decimal Size2;

		[XmlAttribute("sheetIndex")]
		public Int32 SheetIndex;

		/*
		 * Статистика раскроя
		 */
		[XmlAttribute("scrapsSquare")]
		public Double ScrapsSquare;

		[XmlAttribute("totalSquare")]
		public Double TotalSquare;

		[XmlAttribute("remainsCount")]
		public Int32 RemainsCount;

		[XmlAttribute("remainsSquare")]
		public Double RemainsSquare;

		[XmlAttribute("dustSquare")]
		public Double DustSquare; // Опилки

		[XmlAttribute("detailsCount")]
		public Int32 DetailsCount;

		[XmlAttribute("detailsSquare")]
		public Double DetailsSquare;

		[XmlAttribute("scrapPercent")]
		public Double ScrapPercent;

		[XmlElement("section")]
		public List<LC4Section> Sections = new List<LC4Section>();

		[XmlElement("variable")]
		public List<LC4Variable> Variables = new List<LC4Variable>();

		[XmlAttribute("someString1")]
		public String SomeString1;

		[XmlAttribute("someInteger1")]
		public Int32 SomeInteger1;

		[XmlAttribute("someInteger2")]
		public Int32 SomeInteger2;

		[XmlAttribute("someInteger3")]
		public Int32 SomeInteger3;

		[XmlAttribute("someInteger4")]
		public Int32 SomeInteger4;

		[XmlAttribute("someInteger5")]
		public Int32 SomeInteger5;

		[XmlAttribute("someString2")]
		public String SomeString2;

		[XmlAttribute("someInteger6")]
		public Int32 SomeInteger6;

		[XmlAttribute("someInteger8")]
		public Int32 SomeInteger8;

		[XmlAttribute("someInteger9")]
		public Int32 SomeInteger9;

		[XmlAttribute("someInteger10")]
		public Int32 SomeInteger10;

		[XmlAttribute("someString3")]
		public String SomeString3;

		[XmlAttribute("someInteger11")]
		public Int32 SomeInteger11;

		[XmlAttribute("someInteger12")]
		public Int32 SomeInteger12;

		public LC4Cutting()
		{
			SomeInteger1 = 1;
			SomeInteger2 = 1;
			SomeInteger3 = 1;
			SomeInteger4 = 1;
			SomeInteger5 = 0;
			SomeInteger6 = 3;
			SomeInteger8 = 0;
			SomeInteger9 = 1; // can be 2, 3, 4, 5, 7, 32, may be others. Correlate with LC4Sheet.SomeInetger2.
			SomeInteger10 = 1;
			SomeInteger11 = 0;
			SomeInteger12 = 1; // can be 2, 3, 4, 5, 13 and others. Correlate with LC4Sheet.SomeInetger2.
			SomeString1 = "";
			SomeString2 = "";
			SomeString3 = "";
		}
	}
}
