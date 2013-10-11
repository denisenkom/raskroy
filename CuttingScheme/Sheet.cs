using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	public class Sheet : ICloneable, IEquatable<Sheet>, IComparable<Sheet>
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

        #region IEquatable<Sheet> Members

        bool IEquatable<Sheet>.Equals(Sheet other)
        {
            return m_length == other.m_length && m_width == other.m_width && m_thickness == other.m_thickness;
        }

        #endregion


        // override object.Equals
        public override bool Equals(object obj)
        {

            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }

            return Equals((Sheet)obj);
        }

        // override object.GetHashCode
        public override int GetHashCode()
        {
            return m_length.GetHashCode() | m_width.GetHashCode() | m_thickness.GetHashCode();
        }

        #region IComparable<Sheet> Members

        int IComparable<Sheet>.CompareTo(Sheet other)
        {
            decimal delta = Width - other.Width;
            if (delta > 0.0M)
            {
                return 1;
            }
            else if (delta == 0.0M)
            {
                delta = Height - other.Height;
                if (delta > 0.0M)
                {
                    return 1;
                }
                else if (delta == 0.0M)
                {
                    delta = Thickness - other.Thickness;
                    if (delta > 0.0M)
                    {
                        return 1;
                    }
                    else if (delta == 0.0M)
                    {
                        return 0;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }

        #endregion
    }
}
