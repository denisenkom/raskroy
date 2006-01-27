using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.Cutting.LC4
{
	public class LC4SheetsCollection : IEnumerable<LC4Sheet>
	{
		private XmlElement m_element;
		private List<LC4Sheet> m_sheetsList = new List<LC4Sheet>();

		internal LC4SheetsCollection(XmlElement element)
		{
			m_element = element;
		}

		public void Add(LC4Sheet sheet)
		{
			m_element.AppendChild(sheet.m_element);
			m_sheetsList.Add(sheet);
		}

		public IEnumerator<LC4Sheet> GetEnumerator()
		{
			return m_sheetsList.GetEnumerator();
		}

		public Int32 Count
		{
			get { return m_sheetsList.Count; }
		}

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return GetEnumerator();
		}
	}
}
