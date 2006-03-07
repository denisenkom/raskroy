using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public class LC4Document
	{
		[XmlAttribute("internalName")]
		public String InternalName;

		[XmlAttribute("description")]
		public String Description;

		[XmlElement("sheet")]
		public List<LC4Sheet> Sheets = new List<LC4Sheet>();

		[XmlElement("cutting")]
		public List<LC4Cutting> Cuttings = new List<LC4Cutting>();

		[XmlAttribute("someInteger1")]
		public Int32 SomeInteger1;

		[XmlAttribute("someInteger2")]
		public Int32 SomeInteger2;

		public void Serialize(String fileName)
		{
			using (XmlWriter textWriter = XmlWriter.Create(fileName))
			{
				XmlSerializer serializer = new XmlSerializer(typeof(LC4Document));
				serializer.Serialize(textWriter, this);
			}
		}

		public LC4Document()
		{
			SomeInteger1 = 0;
			SomeInteger2 = 0;
		}
	}
}
