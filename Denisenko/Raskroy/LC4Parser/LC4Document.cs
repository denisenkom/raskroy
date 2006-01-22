using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.Cutting.LC4
{
	public class LC4Document : XmlDocument
	{
		private LC4SheetsCollection m_sheetsCollection;
		private LC4CuttingsCollection m_cuttingsCollection;

		public LC4Document()
		{
			this.AppendChild(CreateElement("lc4Document"));

			XmlElement sheetsElement = CreateElement("sheets");
			DocumentElement.AppendChild(sheetsElement);
			m_sheetsCollection = new LC4SheetsCollection(sheetsElement);

			XmlElement cuttingsElement = CreateElement("cuttings");
			DocumentElement.AppendChild(cuttingsElement);
			m_cuttingsCollection = new LC4CuttingsCollection(cuttingsElement);
		}

		public String InternalName
		{
			get
			{
				return DocumentElement.Attributes["internalName"].Value;
			}
			set 
			{
				SetAttribute(DocumentElement.Attributes, "internalName", value);
			}
		}

		public String Generator
		{
			get
			{
				return DocumentElement.Attributes["generator"].Value;
			}
			set
			{
				SetAttribute(DocumentElement.Attributes, "generator", value);
			}
		}

		public LC4SheetsCollection Sheets
		{
			get
			{
				return m_sheetsCollection;
			}
		}

		public LC4CuttingsCollection Cuttings
		{
			get
			{
				return m_cuttingsCollection;
			}
		}

		private void SetAttribute(XmlAttributeCollection attributes, String tag, String value)
		{
			if (attributes[tag] == null)
			{
				XmlAttribute attrib = CreateAttribute(tag);
				attributes.Append(attrib);
			}
			attributes[tag].Value = value;
		}

		public LC4Sheet CreateSheet()
		{
			XmlElement element = CreateElement("sheet");
			element.Attributes.Append(CreateAttribute("size1"));
			element.Attributes.Append(CreateAttribute("size2"));
			element.Attributes.Append(CreateAttribute("thickness"));
			return new LC4Sheet(element);
		}

		public LC4Cutting CreateCutting()
		{
			XmlElement element = CreateElement("cutting");
			element.Attributes.Append(CreateAttribute("name"));
			element.Attributes.Append(CreateAttribute("size1"));
			element.Attributes.Append(CreateAttribute("size2"));
			return new LC4Cutting(element);
		}

		public LC4Section CreateSection()
		{
			XmlElement element = CreateElement("section");
			XmlAttribute typeAttr = CreateAttribute("type");
			element.Attributes.Append(typeAttr);
			XmlAttribute sizeAttr = CreateAttribute("size");
			element.Attributes.Append(sizeAttr);
			return new LC4Section(element, typeAttr, sizeAttr);
		}

		public LC4VariablesCollection CreateVariablesCollection()
		{
			XmlElement element = CreateElement("variables");
			return new LC4VariablesCollection(element);
		}

		public LC4Variable CreateVariable()
		{
			XmlElement element = CreateElement("variable");
			element.Attributes.Append(CreateAttribute("name"));
			element.Attributes.Append(CreateAttribute("value"));
			return new LC4Variable(element);
		}
	}
}
