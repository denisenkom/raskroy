using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	public class Sheet : ICloneable
	{
		public Sheet()
		{
		}

		public Decimal Width { get { return m_length; } set { m_length = value; } }
		public Decimal Height { get { return m_width; } set { m_width = value; } }
		public Decimal Thickness { get { return m_thickness; } set { m_thickness = value; } }

		private Decimal m_length;
		private Decimal m_width;
		private Decimal m_thickness;

        #region ICloneable Members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion
    }
}
