using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.Cutting.LC4
{
	public class LC4Sheet
	{
		internal XmlElement m_element;
		private XmlAttribute m_size1Attribute;
		private XmlAttribute m_size2Attribute;
		private XmlAttribute m_thicknessAttribute;

		internal LC4Sheet(XmlElement element)
		{
			m_element = element;
			m_size1Attribute = element.Attributes["size1"];
			m_size2Attribute = element.Attributes["size2"];
			m_thicknessAttribute = element.Attributes["thickness"];
		}

		public LC4Numeric Size1
		{
			get { return LC4Numeric.FromScaled(Int64.Parse(m_size1Attribute.Value)); }
			set { m_size1Attribute.Value = value.Scaled.ToString(); }
		}

		public LC4Numeric Size2
		{
			get { return LC4Numeric.FromScaled(Int64.Parse(m_size2Attribute.Value)); }
			set { m_size2Attribute.Value = value.Scaled.ToString(); }
		}

		public LC4Numeric Thickness
		{
			get { return LC4Numeric.FromScaled(Int64.Parse(m_thicknessAttribute.Value)); }
			set { m_thicknessAttribute.Value = value.Scaled.ToString(); }
		}
	}
}
