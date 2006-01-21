using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.LC4Parser
{
	public class LC4Variable
	{
		internal XmlElement m_element;
		internal XmlAttribute m_variableNameAttribute;
		internal XmlAttribute m_variableValueAttribute;

		internal LC4Variable(XmlElement element)
		{
			m_element = element;
			m_variableNameAttribute = m_element.Attributes["name"];
			m_variableValueAttribute = m_element.Attributes["value"];
		}

		public String Name
		{
			get { return m_variableNameAttribute.Value; }
			set { m_variableNameAttribute.Value = value; }
		}

		public String Value
		{
			get { return m_variableValueAttribute.Value; }
			set { m_variableValueAttribute.Value = value; }
		}
	}
}
