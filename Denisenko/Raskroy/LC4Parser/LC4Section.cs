using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public enum LC4SectionType {
		Invalid0,
		Invalid1,
		Schnitt, // Schnitt - 2
		Streifen, // Streifen - 3
		Anschnitt, // Aunschnitt - 4
		Invalid5,
		Invalid6,
		Invalid7,
		Invalid8,
		Invalid9,
		Rest, // 10
		Teil, // 11
	}

	public class LC4Section
	{
		[XmlAttribute("sectionType")]
		public LC4SectionType SectionType;

		[XmlAttribute("copyString")]
		public String CopyString;

		[XmlAttribute("size")]
		public Decimal Size;

		[XmlAttribute("someInteger1")]
		public Int32 SomeInteger1;

		[XmlAttribute("someInteger2")]
		public Int32 SomeInteger2;

		[XmlAttribute("someInteger3")]
		public Int32 SomeInteger3;

		[XmlAttribute("someInteger4")]
		public Int32 SomeInteger4;

		[XmlElement("section")]
		public List<LC4Section> NestedSections = new List<LC4Section>();

		public LC4Section()
		{
			SomeInteger1 = 1;
			SomeInteger2 = 0; // may be 1, 4. Correlate with section type. For schnitt, anschnitt and rest = 4, for streifen and teil = 0
			SomeInteger3 = 0;
			SomeInteger4 = 0;
			CopyString = "";
		}
	}
}
