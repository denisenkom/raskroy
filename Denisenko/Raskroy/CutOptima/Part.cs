using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	public class Part
	{
		public Dictionary<PropertyType, String> Properties;

		public Part()
		{
			Properties = new Dictionary<PropertyType, String>();
		}

		public String Name
		{
			get { return m_name; }
			set { m_name = value; }
		}

		private String m_name;
	}
}
