using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.LC4Parser
{
	public class LC4VariablesCollection : IEnumerable<LC4Variable>
	{
		internal XmlElement m_element;
		internal List<LC4Variable> m_list = new List<LC4Variable>();

		internal LC4VariablesCollection(XmlElement element)
		{
			m_element = element;
		}

		public void Add(LC4Variable item)
		{
			m_element.AppendChild(item.m_element);
			m_list.Add(item);
		}

		public IEnumerator<LC4Variable> GetEnumerator()
		{
			return m_list.GetEnumerator();
		}

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return GetEnumerator();
		}
	}
}
