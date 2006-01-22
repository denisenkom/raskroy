using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Denisenko.Cutting.LC4
{
	public class SomeEnum : IEnumerator<Int16>
	{
		public Int16 Current
		{
			get
			{
				return 7;
			}
		}

		Object System.Collections.IEnumerator.Current { get { return null; } }

		public void Dispose() {	}
		public bool MoveNext() { return false; }
		public void Reset() { }


	}

	public class LC4SheetsEnumerator : IEnumerator<LC4Sheet>
	{
		private List<LC4Sheet>.Enumerator m_enumerator;

		public void Reset()
		{
			((System.Collections.IEnumerator)m_enumerator).Reset();
		}

		public LC4Sheet Current
		{
			get { return (LC4Sheet)m_enumerator.Current; }
		}

		Object System.Collections.IEnumerator.Current { get { return Current; } }

		public bool MoveNext()
		{
			return m_enumerator.MoveNext();
		}

		public void Dispose()
		{
			m_enumerator.Dispose();
		}
	}

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

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return GetEnumerator();
		}
	}
}
