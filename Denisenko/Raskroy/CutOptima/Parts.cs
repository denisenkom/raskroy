using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	public class Parts : CollectionBase
	{
		public virtual Int32 Add(Part part)
		{
			return this.InnerList.Add(part);
		}
	}
}
