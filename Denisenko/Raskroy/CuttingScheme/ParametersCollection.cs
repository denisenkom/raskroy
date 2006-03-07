using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	[Serializable]
	public class ParametersCollection
	{
		public Decimal CutterThickness
		{
			get { return m_cutterThickness; }
			set { m_cutterThickness = value; }
		}

		public Decimal CutOffTop;
		public Decimal CutOffBottom;
		public Decimal CutOffLeft;
		public Decimal CutOffRight;

		public ParametersCollection Clone()
		{
			return (ParametersCollection)MemberwiseClone();
		}

		public ParametersCollection()
		{
			m_cutterThickness = 4.4M;
			CutOffTop = 12;
			CutOffBottom = 12;
			CutOffLeft = 12;
			CutOffRight = 12;
		}

		private Decimal m_cutterThickness;
	}
}
