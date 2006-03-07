using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	[Serializable]
	public class CuttingScheme
	{
		public Section Cut(Section section, Decimal size, CutType cutType, out Section remain)
		{
			if(section.CutType != cutType)
			{
				section = CreateNestedSection(section, cutType);
			}
			return SplitSection(section, size, cutType, out remain);
		}

		public void MakeSureEdgeEven(ref Section section, CutType cutType)
		{
			if(cutType == CutType.Horizontal && !section.IsTopEven())
				Cut(section, m_parameters.CutOffLeft - m_parameters.CutterThickness, cutType, out section);
			else if(cutType == CutType.Vertical && !section.IsLeftEven())
				Cut(section, m_parameters.CutOffLeft - m_parameters.CutterThickness, cutType, out section);
		}

		/*public Section Cut(Decimal size, out Section remain)
		{
			throw new NotImplementedException();
		}

		public Section CutPart(Section section, Part part, CutType cutType, out Section remain)
		{
			throw new NotImplementedException();
		}

		public Section CutPart(Part part, out Section remain)
		{
			throw new NotImplementedException();
		}*/

		public void MarkAsPart(Section section)
		{
			section.m_sectionType = SectionType.Element;
		}

		/*public void MarkAsRemain(Section section)
		{
			throw new NotImplementedException();
		}*/

		public static CutType Rotate(CutType cutType)
		{
			if(cutType == CutType.Vertical)
				return CutType.Horizontal;
			else
				return CutType.Vertical;
		}

		public CuttingScheme()
		{
			m_rootSection = new Section();
		}

		public  Section RootSection
		{
			get { return m_rootSection; }
		}

		public Decimal Width
		{
			get { return m_rootSection.Width; }
			set { m_rootSection.Width = value; }
		}

		public Decimal Height
		{
			get { return m_rootSection.Height; }
			set { m_rootSection.Height = value; }
		}

		public Material Material
		{
			get { return m_material; }
			set { m_material = value; }
		}

		private Section m_rootSection;
		private ParametersCollection m_parameters;

		public ParametersCollection Parameters
		{
			get { return m_parameters; }
			set { m_parameters = value; }
		}

		private Material m_material;

		private Section SplitSection(Section section, Decimal size, CutType cutType, out Section remain)
		{
			Debug.Assert(cutType == section.CutType);

			Section section1 = new Section();
			Section cut = new Section();
			remain = new Section();

			section1.m_parent = cut.m_parent = remain.m_parent = section.m_parent;
			section1.m_cutType = cut.m_cutType = remain.m_cutType = cutType;
			section1.m_sectionType = remain.m_sectionType = SectionType.Undefined;
			cut.m_sectionType = SectionType.Cut;
			if(cutType == CutType.Horizontal)
			{
				if (size > section.m_height)
				{
					throw new Exception("Section is too small");
				}
				section1.m_topEven = section.m_topEven;
				section1.m_x = cut.m_x = remain.m_x = section.m_x;
				section1.m_y = section.m_y;
				section1.m_width = cut.m_width = remain.m_width = section.m_width;
				section1.m_height = size;
				section1.m_bottomEven = true;
				cut.m_y = section.m_y + size;
				cut.m_height = Math.Min(m_parameters.CutterThickness, section.m_height - size);
				remain.m_topEven = true;
				remain.m_bottomEven = section.m_bottomEven;
				section1.m_leftEven = remain.m_leftEven = section.m_leftEven;
				section1.m_rightEven = remain.m_rightEven = section.m_rightEven;
				remain.m_y = section.m_y + size + m_parameters.CutterThickness;
				remain.m_height = section.m_height - size - m_parameters.CutterThickness;
				if (remain.m_height < Decimal.Zero)
				{
					remain = null;
				}
			}
			else // Vertical
			{
				if (size > section.m_width)
				{
					throw new Exception("Section is too small");
				}
				section1.m_x = section.m_x;
				section1.m_y = cut.m_y = remain.m_y = section.m_y;
				section1.m_height = cut.m_height = remain.m_height = section.m_height;
				section1.m_width = size;
				section1.m_rightEven = true;
				section1.m_leftEven = section.m_leftEven;
				cut.m_x = section.m_x + size;
				cut.m_width = Math.Min(m_parameters.CutterThickness, section.m_width - size);
				remain.m_leftEven = true;
				remain.m_rightEven = section.m_rightEven;
				section1.m_topEven = remain.m_topEven = section.m_topEven;
				section1.m_bottomEven = remain.m_bottomEven = section.m_bottomEven;
				remain.m_x = section.m_x + size + m_parameters.CutterThickness;
				remain.m_width = section.m_width - size - m_parameters.CutterThickness;
				if (remain.m_width < Decimal.Zero)
				{
					remain = null;
				}
			}

			section.m_parent.NestedSections[section.m_parent.NestedSections.IndexOf(section)] = section1;
			section.m_parent.NestedSections.Insert(section.m_parent.NestedSections.IndexOf(section1) + 1, cut);
			if (remain != null)
			{
				section.m_parent.NestedSections.Insert(section.m_parent.NestedSections.IndexOf(cut) + 1, remain);
			}
			return section1;
		}

		private Section CreateNestedSection(Section section, CutType cutType)
		{
			Section result = new Section();
			result.m_x = section.m_x;
			result.m_y = section.m_y;
			result.m_width = section.m_width;
			result.m_height = section.m_height;
			result.m_cutType = cutType;
			result.m_parent = section;
			result.m_topEven = section.m_topEven;
			result.m_leftEven = section.m_leftEven;
			result.m_bottomEven = section.m_bottomEven;
			result.m_rightEven = section.m_rightEven;
			section.m_sectionType = SectionType.NewLine;
			section.NestedSections.Add(result);
			return result;
		}

		public Sheet Sheet
		{
			get
			{
				return m_sheet;
			}
			set
			{
				m_sheet = value;
				m_rootSection.Width = m_sheet.Width;
				m_rootSection.Height = m_sheet.Height;
			}
		}

		private Sheet m_sheet;
	};
}
