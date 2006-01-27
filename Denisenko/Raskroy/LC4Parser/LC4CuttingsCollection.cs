using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.Cutting.LC4
{
	public class LC4CuttingsCollection : IEnumerable<LC4Cutting>
	{
		XmlElement m_element;
		List<LC4Cutting> m_list = new List<LC4Cutting>();

		public LC4CuttingsCollection(XmlElement element)
		{
			m_element = element;
		}

		public void Add(LC4Cutting item)
		{
			m_element.AppendChild(item.m_element);
			m_list.Add(item);
		}

		public LC4Cutting this[Int32 index]
		{
			get { return m_list[index]; }
		}

		public IEnumerator<LC4Cutting> GetEnumerator()
		{
			return m_list.GetEnumerator();
		}

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return GetEnumerator();
		}
	}
}
