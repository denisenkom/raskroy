using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting
{
	[Serializable]
	public class CuttingScheme : ICloneable
	{
        public delegate void ChangeHandler(CuttingScheme sender);

        public event ChangeHandler Change;

        #region Undo redo support

        const int MaxHistory = 64;
        Section[] m_history = new Section[MaxHistory];
        int m_historyBegin = 0;
        int m_historyEnd = 0;
        int m_historyCurrent = 0;

        public void Undo()
        {
            if (m_historyCurrent > m_historyBegin)
            {
                m_historyCurrent--;
                m_rootSection = m_history[m_historyCurrent];
                NotifyViews();
            }
        }

        public void Redo()
        {
            if (m_historyCurrent < m_historyEnd)
            {
                m_historyCurrent++;
                m_rootSection = m_history[m_historyCurrent];
                NotifyViews();
            }
        }

        #endregion

        public Section Cut(Section section, Decimal size, CutType cutType, out Section remain)
		{
			if(section.CutType != cutType)
			{
				section = CreateNestedSection(section, cutType);
			}
            Section result = SplitSection(section, size, cutType, out remain);
            Changed();
            return result;
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
            section.m_data.m_sectionType = SectionType.Element;
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
			m_rootSection = new Section(this);
		}

        public CuttingScheme(CuttingScheme orig)
        {
            m_rootSection = new Section(orig.m_rootSection, null, this);
            if (orig.m_parameters != null)
            {
                m_parameters = orig.m_parameters.Clone();
            }
            if (orig.m_material != null)
            {
                m_material = (Material)orig.m_material.Clone();
            }
            if (orig.m_sheet != null)
            {
                m_sheet = (Sheet)orig.m_sheet.Clone();
            }
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

            // создаём и инициализируем 3 новые подсекции, одна типа разрез и две свободные
            // в случае если для остатка не остаётся места то будет создано лишь 2 секции
			Section cut = new Section(this);
			cut.m_parent = section.m_parent;
            cut.m_data.m_cutType = cutType;
            cut.m_data.m_sectionType = SectionType.Cut;
			if(cutType == CutType.Horizontal)
			{
                if (size > section.m_data.m_height)
				{
					throw new Exception("Section is too small");
				}
                cut.m_data.m_x = section.m_data.m_x;
                cut.m_data.m_y = section.m_data.m_y + size;
                cut.m_data.m_width = section.m_data.m_width;
                cut.m_data.m_height = Math.Min(m_parameters.CutterThickness, section.m_data.m_height - size);
                decimal remainHeight = section.m_data.m_height - size - m_parameters.CutterThickness;
                if (remainHeight > decimal.Zero)
                {
                    remain = new Section(this);
                    remain.m_data.m_topEven = true;
                    remain.m_data.m_bottomEven = section.m_data.m_bottomEven;
                    remain.m_data.m_leftEven = section.m_data.m_leftEven;
                    remain.m_data.m_rightEven = section.m_data.m_rightEven;
                    remain.m_data.m_x = section.m_data.m_x;
                    remain.m_data.m_y = section.m_data.m_y + size + m_parameters.CutterThickness;
                    remain.m_data.m_width = section.m_data.m_width;
                    remain.m_data.m_height = remainHeight;
                }
                else
                {
                    remain = null;
                }
                section.m_data.m_bottomEven = true;
                section.m_data.m_height = size;
			}
			else // Vertical
			{
                if (size > section.m_data.m_width)
				{
					throw new Exception("Section is too small");
				}
                cut.m_data.m_x = section.m_data.m_x + size;
                cut.m_data.m_y = section.m_data.m_y;
                cut.m_data.m_width = Math.Min(m_parameters.CutterThickness, section.m_data.m_width - size);
                cut.m_data.m_height = section.m_data.m_height;
                decimal remainWidth = section.m_data.m_width - size - m_parameters.CutterThickness;
                if (remainWidth > decimal.Zero)
                {
                    remain = new Section(this);
                    remain.m_data.m_leftEven = true;
                    remain.m_data.m_rightEven = section.m_data.m_rightEven;
                    remain.m_data.m_topEven = section.m_data.m_topEven;
                    remain.m_data.m_bottomEven = section.m_data.m_bottomEven;
                    remain.m_data.m_x = section.m_data.m_x + size + m_parameters.CutterThickness;
                    remain.m_data.m_y = section.m_data.m_y;
                    remain.m_data.m_width = remainWidth;
                    remain.m_data.m_height = section.m_data.m_height;
                }
                else
                {
                    remain = null;
                }
                section.m_data.m_rightEven = true;
                section.m_data.m_width = size;
			}

            // заменяем ту секцию, которую мы разрезали на новую, отрезанную секцию
            // и вставляем 2 оставшиеся секции после неё в списоке подсекций родительской секции
            section.m_parent.NestedSections.AddAfter(section.m_parent.NestedSections.Find(section), cut);
			if (remain != null)
			{
                remain.m_data.m_cutType = cutType;
                remain.m_data.m_sectionType = SectionType.Free;
                remain.m_parent = section.m_parent;
                section.m_parent.NestedSections.AddAfter(section.m_parent.NestedSections.Find(cut), remain);
			}

			return section;
		}

		private Section CreateNestedSection(Section section, CutType cutType)
		{
			Section result = new Section(this);
            result.m_data.m_x = section.m_data.m_x;
            result.m_data.m_y = section.m_data.m_y;
            result.m_data.m_width = section.m_data.m_width;
            result.m_data.m_height = section.m_data.m_height;
            result.m_data.m_cutType = cutType;
			result.m_parent = section;
            result.m_data.m_topEven = section.m_data.m_topEven;
            result.m_data.m_leftEven = section.m_data.m_leftEven;
            result.m_data.m_bottomEven = section.m_data.m_bottomEven;
            result.m_data.m_rightEven = section.m_data.m_rightEven;
            result.m_data.m_sectionType = SectionType.Free;
            section.m_data.m_sectionType = SectionType.NewLine;
			section.NestedSections.AddLast(result);
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

		public Statistics CalcStatistics()
		{
			Statistics result = new Statistics();
			RecursiveAddStatistics(ref result, this.RootSection);
			return result;
		}

		private void RecursiveAddStatistics(ref Statistics statistics, Section section)
		{
			Double sectionSquare = (Double)section.Width * (Double)section.Height;
			if (section.SectionType == SectionType.Cut)
			{
				statistics.DustSquare += sectionSquare;
				statistics.CutsCount++;
			}
			else if(section.SectionType == SectionType.Element)
			{
				statistics.DetailsSquare += sectionSquare;
				statistics.DetailsCount++;
			}
			else if (section.SectionType == SectionType.Remain)
			{
				statistics.RemainsSquare += sectionSquare;
				statistics.RemainsCount++;
			}
			else if (section.SectionType == SectionType.Scrap)
			{
				statistics.ScrapsSquare += sectionSquare;
				statistics.ScrapsCount++;
			}
			else if (section.SectionType == SectionType.Free)
			{
				statistics.UndefinitesSquare += sectionSquare;
				statistics.UndefinitesCount++;
			}
			foreach(Section nested in section.NestedSections)
			{
				RecursiveAddStatistics(ref statistics, nested);
			}
		}

        internal void Changed()
        {
            NotifyViews();
            m_historyCurrent = (m_historyCurrent + 1) % MaxHistory;
            if (m_historyBegin == m_historyCurrent)
            {
                m_historyBegin = (m_historyBegin + 1) % MaxHistory;
            }
            m_historyEnd = m_historyCurrent;
            m_history[m_historyCurrent] = new Section(m_rootSection, null, this);
        }

        private void NotifyViews()
        {
            if (Change != null)
            {
                Change.Invoke(this);
            }
        }

        #region ICloneable Members

        public object Clone()
        {
            return new CuttingScheme(this);
        }

        #endregion
    };
}
