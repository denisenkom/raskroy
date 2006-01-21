using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.LC4Parser
{
	public enum LC4SectionType {
		Scrap,
		NewLine,
		Detail,
		Remain,
		Cut
	}

	public class LC4Section : LC4SectionsCollection
	{
		internal XmlElement m_element;
		private XmlAttribute m_shiftAttribute;
		private XmlAttribute m_typeAttribute;

		internal LC4Section(XmlElement element, XmlAttribute typeAttr, XmlAttribute sizeAttr) : base(element)
		{
			m_element = element;
			m_typeAttribute = typeAttr;
			m_shiftAttribute = sizeAttr;
		}

		public LC4SectionType SectionType
		{
			get { return (LC4SectionType)Enum.Parse(typeof(LC4SectionType), m_typeAttribute.Value); }
			set { m_typeAttribute.Value = value.ToString(); }
		}

		public LC4Numeric Size
		{
			get { return LC4Numeric.FromScaled(Int64.Parse(m_shiftAttribute.Value)); }
			set { m_shiftAttribute.Value = value.Scaled.ToString(); }
		}
	}
}
