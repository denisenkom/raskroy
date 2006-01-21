using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.LC4Parser
{
	public class LC4Cutting : LC4SectionsCollection
	{
		internal XmlElement m_element;
		private XmlAttribute m_nameAttribute;
		private XmlAttribute m_size1Attribute;
		private XmlAttribute m_size2Attribute;
		private LC4VariablesCollection m_variables;

		public LC4Cutting(XmlElement element) : base(element)
		{
			m_element = element;
			m_nameAttribute = element.Attributes["name"];
			m_size1Attribute = element.Attributes["size1"];
			m_size2Attribute = element.Attributes["size2"];
		}

		public String Name
		{
			get { return m_nameAttribute.Value; }
			set	{ m_nameAttribute.Value = value; }
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

		public LC4VariablesCollection Variables
		{
			get { return m_variables; }
			set {
				if (m_variables == value)
					return;
				if (m_variables != null)
				{
					m_element.RemoveChild(m_variables.m_element);
				}
				m_variables = value;
				m_element.AppendChild(m_variables.m_element);
			}
		}
	}
}
