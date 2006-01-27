using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.Cutting.LC4
{
	public class LC4SectionsCollection : IEnumerable<LC4Section>
	{
		private XmlElement m_element;
		private List<LC4Section> m_list = new List<LC4Section>();

		public LC4SectionsCollection(XmlElement element)
		{
			m_element = element;
		}

		public void Add(LC4Section item)
		{
			m_element.AppendChild(item.m_element);
			m_list.Add(item);
		}

		public Int32 Count
		{
			get { return m_list.Count; }
		}

		public IEnumerator<LC4Section> GetEnumerator()
		{
			return m_list.GetEnumerator();
		}

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return GetEnumerator();
		}
	}
}
