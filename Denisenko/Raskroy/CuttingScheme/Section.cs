using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	public enum SectionType
	{
		Undefined,
		NewLine,
		Scrap,
		Cut,
		Element,
		Remain
	}


	public enum CutType
	{
		Undefined,
		Vertical,
		Horizontal
	}

	[Serializable]
	public class Section : ICloneable
	{
		Object ICloneable.Clone()
		{
			return Clone();
		}

		public Section Clone()
		{
			return new Section(this);
		}

		public Decimal Size
		{
			get
			{
				switch(m_cutType)
				{
				case CutType.Horizontal:
					return m_height;
				case CutType.Vertical:
					return m_width;
				case CutType.Undefined:
					throw new Exception("Cannot get size of section with undefined cutting");
				}
				throw new Exception("Never should get here");
			}
		}

		public SectionType SectionType { get { return m_sectionType; } }
		public CutType CutType { get { return m_cutType; } }
		public Section Parent { get { return m_parent; } }
		public Decimal X { get { return m_x; } }
		public Decimal Y { get { return m_y; } }
		public Decimal Width
		{
			get { return m_width; }
			set
			{
				if (m_nestedSections.Count != 0)
					throw new ApplicationException("Нельзя изменять размеры элементов, содержащих другие элементы.");
				// TODO: изменить размеры siblings
				m_width = value;
			}
		}
		public Decimal Height
		{
			get { return m_height; }
			set
			{
				if (m_nestedSections.Count != 0)
					throw new ApplicationException("Нельзя изменять размеры элементов, содержащих другие элементы.");
				// TODO: изменить размеры siblings
				m_height = value;
			}
		}
		public List<Section> NestedSections { get { return m_nestedSections; } }

		public Boolean IsLeftEven()
		{
			return m_leftEven;
		}
		public Boolean IsRightEven()
		{
			return m_rightEven;
		}
		public Boolean IsTopEven()
		{
			return m_topEven;
		}
		public Boolean IsBottomEven()
		{
			return m_bottomEven;
		}

		internal Decimal m_x;
		internal Decimal m_y;
		internal Decimal m_width;
		internal Decimal m_height;
		internal CutType m_cutType;
		internal SectionType m_sectionType;
		internal Section m_parent;
		internal Boolean m_topEven;
		internal Boolean m_leftEven;
		internal Boolean m_bottomEven;
		internal Boolean m_rightEven;
		List<Section> m_nestedSections;

		internal Section()
		{
			m_nestedSections = new List<Section>();
		}

		Section(Section original)
		{
			m_nestedSections = new List<Section>(original.m_nestedSections);
			m_sectionType = original.m_sectionType;
			m_width = original.m_width;
			m_height = original.m_height;
			m_cutType = original.m_cutType;
			m_parent = null;
		}
	}
}
