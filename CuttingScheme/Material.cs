using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	public class Material : ICloneable
	{
		private Int32 m_materialID;
		private String m_name;
		private Boolean m_canRotate;

		public Material(Int32 materialID, String name, Boolean canRotate)
		{
			m_materialID = materialID;
			m_name = name;
			m_canRotate = canRotate;
		}

		public Material(Material original)
		{
			m_materialID = original.m_materialID;
			m_name = original.m_name;
			m_canRotate = original.m_canRotate;
		}

		public Int32 MaterialID { get { return m_materialID; } }
		public String Name { get { return m_name; } }
		public Boolean CanRotate { get { return m_canRotate; } }

        #region ICloneable Members

        public object Clone()
        {
            return MemberwiseClone();
        }

        #endregion
    }
}
