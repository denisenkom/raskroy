using System;

namespace Denisenko.Cutting.LC4
{
	public struct LC4Numeric
	{
		private Int64 m_scaled;
        private bool m_isNaN;
		public const Int64 Scale = 100000;

		public Double ToDouble()
		{
			return (Double)m_scaled / (Double)Scale;
		}

		public override String ToString()
		{
			return ToDouble().ToString();
		}

		public static LC4Numeric FromScaled(Int64 scaled)
		{
			return new LC4Numeric(scaled);
		}

		public static LC4Numeric FromNonScaled(Int32 nonScaled)
		{
			return new LC4Numeric(nonScaled * Scale);
		}

		public Int64 Scaled
		{
			get { return m_scaled; }
			set { m_scaled = value; }
		}

		private LC4Numeric(Int64 scaled)
		{
			m_scaled = scaled;
            m_isNaN = false;
		}

		public static implicit operator LC4Numeric(Decimal value)
		{
			return new LC4Numeric((Int64)(value * Scale));
		}

		public static implicit operator Decimal(LC4Numeric num)
		{
			return new Decimal(num.m_scaled) / Scale;
		}

        internal void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out m_scaled);
            fmtr.Read(out m_isNaN);
        }

        internal void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            fmtr.Write(m_scaled);
            fmtr.Write(m_isNaN);
        }
	}

    public enum e_HOUnit
    {
        none = 0,
        count = 1,
        length_mm = 2,
        length_cm = 3,
        length_m = 4,
        length_inch = 5,
        length_fracinch = 6,
        length_feet = 7,
        area_m2 = 8,
        area_feet2 = 9,
        volume_m3 = 10,
        angle_grad = 11,
        speed_mMin = 12,
        speed_feetMin = 13,
        pressure_bar = 14,
        pressure_psi = 15,
        time_s = 16,
        time_min = 17,
        percent = 18,
        rotation_1min = 19,
        current_A = 20,
    }

    public struct Measure
    {
        public e_HOUnit Unit;

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out Unit);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            fmtr.Write(Unit);
        }
    }
}
