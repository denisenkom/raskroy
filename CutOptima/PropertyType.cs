using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	public class PropertyType
	{
		public String Id;
		public String Description;

		public PropertyType() { }
		public PropertyType(String id, String description)
		{
			Id = id;
			Description = description;
		}
	}
}
