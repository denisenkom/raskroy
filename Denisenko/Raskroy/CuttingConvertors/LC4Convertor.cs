using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;
using Denisenko.Cutting;
using Denisenko.Cutting.LC4;

namespace Denisenko.Cutting.Converting
{
	public class LC4Convertor
	{
		private List<Sheet> m_sheets;

		public LC4Convertor()
		{
		}

		private LC4Cutting ConvertCuttingScheme(CuttingScheme cuttingResult)
		{
			LC4Cutting lc4Cutting = new LC4Cutting();
			if (cuttingResult.RootSection.NestedSections[0].CutType == CutType.Horizontal)
			{
				lc4Cutting.Size1 = cuttingResult.Width;
				lc4Cutting.Size2 = cuttingResult.Height;
			}
			else
			{
				lc4Cutting.Size1 = cuttingResult.Height;
				lc4Cutting.Size2 = cuttingResult.Width;
			}
			AddSections(lc4Cutting.Sections, cuttingResult.RootSection.NestedSections);
			// TODO: Assign statistics
			return lc4Cutting;
		}

		private void AddSections(List<LC4Section> into, List<Section> sections)
		{
			Section prevSection;
			Section nextSection;
			for (Int32 i = 0; i < sections.Count; i++)
			{
				if(i > 0)
					prevSection = sections[i - 1];
				else
					prevSection = null;
				if(i < sections.Count - 1)
					nextSection = sections[i + 1];
				else
					nextSection = null;
				LC4Section lc4Section = ConvertSection(sections[i], prevSection, nextSection);
				into.Add(lc4Section);
				AddSections(lc4Section.NestedSections, sections[i].NestedSections);
			}
		}

		/*
		 * Предыдущая секция нужна в случае если конвертитуется обрезок, т.к.
		 * его размер должен включать размер реза, который находится перед ним.
		 */
		private LC4Section ConvertSection(Section input, Section prevSection, Section nextSection)
		{
			LC4Section result = new LC4Section();
			result.Size = input.Size;
			switch (input.SectionType)
			{
				case SectionType.Cut:
					result.SectionType = LC4SectionType.Schnitt;
					break;
				case SectionType.Element:
					result.SectionType = LC4SectionType.Teil;
					break;
				case SectionType.NewLine:
					result.SectionType = LC4SectionType.Streifen;
					break;
				case SectionType.Remain:
					result.SectionType = LC4SectionType.Rest;
					break;
				case SectionType.Scrap:
					result.SectionType = LC4SectionType.Anschnitt;
					if (prevSection != null && prevSection.SectionType == SectionType.Cut)
						result.Size = input.Size + prevSection.Size;
					if (nextSection != null && nextSection.SectionType == SectionType.Cut)
						result.Size = input.Size + nextSection.Size;
					break;
				case SectionType.Undefined:
					result.SectionType = LC4SectionType.Anschnitt;
					if (prevSection != null && prevSection.SectionType == SectionType.Cut)
						result.Size = input.Size + prevSection.Size;
					if (nextSection != null && nextSection.SectionType == SectionType.Cut)
						result.Size = input.Size + nextSection.Size;
					break;
			}
			return result;
		}

		public LC4Document Convert(List<CuttingScheme> schemes)
		{
			LC4Document result = new LC4Document();
			Int32 cuttingIndex = 0;
			m_sheets = new List<Sheet>();
			foreach (CuttingScheme scheme in schemes)
			{
				LC4Cutting lc4Cutting = ConvertCuttingScheme(scheme);
				lc4Cutting.Name = cuttingIndex.ToString();
				Int32 sheetIndex = m_sheets.IndexOf(scheme.Sheet);
				if (sheetIndex == -1)
				{
					sheetIndex = m_sheets.Count;
					m_sheets.Add(scheme.Sheet);
					LC4Sheet sheet = new LC4Sheet();
					sheet.Size1 = scheme.Sheet.Width;
					sheet.Size2 = scheme.Sheet.Height;
					sheet.Thickness = scheme.Sheet.Thickness;
					result.Sheets.Add(sheet);
				}
				lc4Cutting.SheetIndex = sheetIndex;
				result.Cuttings.Add(lc4Cutting);
				cuttingIndex++;
			}
			return result;
		}
	}

}
