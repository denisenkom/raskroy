using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	public class Part
	{
		public Part()
		{
		}

		public Decimal Length { get { return m_length; } set { m_length = value; } }
		public Decimal Width { get { return m_width; } set { m_width = value; } }
		public Int32 Quantity { get { return m_quantity; } set { m_quantity = value; } }
		public Boolean CanRotate { get { return m_canRotate; } set { m_canRotate = value; } }

		private Decimal m_length;
		private Decimal m_width;
		private Int32 m_quantity;
		private Boolean m_canRotate;
	}
}
