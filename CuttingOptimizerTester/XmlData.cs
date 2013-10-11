using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace CuttingOptimizerTester
{
	[XmlRoot("cuttingData")]
	public class XmlData
	{
		[XmlElement("material")]
		public List<XmlMaterial> Materials;

		public static XmlData Deserialize(String fileName)
		{
			XmlSerializer serializer = new XmlSerializer(typeof(XmlData));
			using (StreamReader reader = new StreamReader(fileName))
			{
				return (XmlData)serializer.Deserialize(reader);
			}
		}
	}
}
