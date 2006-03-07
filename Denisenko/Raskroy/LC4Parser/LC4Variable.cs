using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public class LC4Variable
	{
		[XmlAttribute("name")]
		public String Name;

		[XmlAttribute("value")]
		public String Value;
	}
}
