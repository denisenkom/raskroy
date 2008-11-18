using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	public enum SectionType
	{
        Free,
		NewLine,
		Scrap,
		Cut,
		Element,
		Remain,
	}


	public enum CutType
	{
		Undefined,
		Vertical,
		Horizontal
	}

	[Serializable]
	public class Section
	{
        public string Label;

		public Decimal Size
		{
			get
			{
                switch (m_data.m_cutType)
				{
				case CutType.Horizontal:
                    return m_data.m_height;
				case CutType.Vertical:
                    return m_data.m_width;
				case CutType.Undefined:
					throw new Exception("Cannot get size of section with undefined cutting");
				}
				throw new Exception("Never should get here");
			}
		}

		public SectionType SectionType
        {
            get
            {
                return m_data.m_sectionType;
            }
            set
            {
                m_data.m_sectionType = value;
                m_scheme.Changed();
            }
        }
        public CutType CutType { get { return m_data.m_cutType; } }
		public Section Parent { get { return m_parent; } }
		public Decimal X { get { return m_data.m_x; } }
        public Decimal Y { get { return m_data.m_y; } }
		public Decimal Width
		{
            get { return m_data.m_width; }
			set
			{
				if (m_nestedSections.Count != 0)
					throw new ApplicationException("Нельзя изменять размеры элементов, содержащих другие элементы.");
				// TODO: изменить размеры siblings
                m_data.m_width = value;
			}
		}
		public Decimal Height
		{
            get { return m_data.m_height; }
			set
			{
				if (m_nestedSections.Count != 0)
					throw new ApplicationException("Нельзя изменять размеры элементов, содержащих другие элементы.");
				// TODO: изменить размеры siblings
                m_data.m_height = value;
			}
		}
		public LinkedList<Section> NestedSections { get { return m_nestedSections; } }

		public Boolean IsLeftEven()
		{
            return m_data.m_leftEven;
		}
		public Boolean IsRightEven()
		{
            return m_data.m_rightEven;
		}
		public Boolean IsTopEven()
		{
            return m_data.m_topEven;
		}
		public Boolean IsBottomEven()
		{
            return m_data.m_bottomEven;
		}

        internal struct Data
        {
            internal Decimal m_x;
            internal Decimal m_y;
            internal Decimal m_width;
            internal Decimal m_height;
            internal CutType m_cutType;
            internal SectionType m_sectionType;
            internal Boolean m_topEven;
            internal Boolean m_leftEven;
            internal Boolean m_bottomEven;
            internal Boolean m_rightEven;
        }

        internal Data m_data;
		internal Section m_parent;
        LinkedList<Section> m_nestedSections;
        internal CuttingScheme m_scheme;

		/*internal Section()
		{
			m_nestedSections = new List<Section>();
		}*/

        public struct CanFitInfo
        {
            public bool CanFit;

            // below members only meaningful if CanFit is true
            public bool CanRotate;
            public bool NeedRotate;
            public bool ExactMatchWidth; // relative to detail (if rotated)
            public bool ExactMatchHeight; // relative to detail (if rotated)
        }

        public CanFitInfo CanFit(decimal width, decimal height, bool canRotate)
        {
            CanFitInfo result = new CanFitInfo();
            if (width <= m_data.m_width && height <= m_data.m_height)
            {
                result.CanFit = true;
                result.CanRotate = canRotate && width <= m_data.m_height && height <= m_data.m_width;
                result.NeedRotate = false;
                result.ExactMatchWidth = width == m_data.m_width;
                result.ExactMatchHeight = height == m_data.m_height;
            }
            else if (canRotate && width <= m_data.m_height && height <= m_data.m_width)
            {
                result.CanFit = true;
                result.CanRotate = false;
                result.NeedRotate = true;
                result.ExactMatchWidth = width == m_data.m_height;
                result.ExactMatchHeight = height == m_data.m_width;
            }
            else
            {
                result.CanFit = false;
            }
            return  result;
        }

        internal Section(CuttingScheme scheme)
        {
            m_nestedSections = new LinkedList<Section>();
            m_scheme = scheme;
        }

		internal Section(Section original, Section parent, CuttingScheme scheme)
		{
            m_data = original.m_data;

            m_nestedSections = new LinkedList<Section>();
            foreach (Section nsec in original.m_nestedSections)
            {
                m_nestedSections.AddLast(new Section(nsec, this, scheme));
            }
            m_parent = parent;
            m_scheme = scheme;
		}
	}
}
