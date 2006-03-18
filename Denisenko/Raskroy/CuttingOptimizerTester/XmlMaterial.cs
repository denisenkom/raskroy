using System;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.Text;

using Denisenko.Cutting;

namespace CuttingOptimizerTester
{
	public class XmlMaterial
	{
		[XmlAttribute("name")]
		public String Name;
		[XmlAttribute("canRotate")]
		public Boolean CanRotate;
		[XmlElement("sheet")]
		public List<XmlSheet> Sheets;
		[XmlElement("part")]
		public List<XmlPart> Parts;

		public void Fill(ICollection<Sheet> sheets, ICollection<Part> parts)
		{
			foreach(XmlSheet xmlSheet in Sheets)
			{
				sheets.Add(xmlSheet.Convert());
			}
			foreach(XmlPart xmlPart in Parts)
			{
				Part part = xmlPart.Convert();
				part.CanRotate = CanRotate;
				parts.Add(part);
			}
		}
	}
}
