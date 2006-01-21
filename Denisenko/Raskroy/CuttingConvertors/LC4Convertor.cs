using System;
using System.Collections.Generic;
using System.Text;
using Denisenko.Cutting;
using Denisenko.LC4Parser;

namespace Denisenko.Cutting.Converting
{
	public class LC4Convertor
	{
		private LC4Document m_result;

		public LC4Document Result { get { return m_result; } }

		public LC4Convertor()
		{
			m_result = new LC4Document();
		}

		public void AddCuttingResult(CuttingResult cuttingResult, String cuttingName)
		{
			LC4Cutting lc4Cutting = m_result.CreateCutting();
			lc4Cutting.Name = cuttingName;
			lc4Cutting.Size1 = new LC4Numeric(cuttingResult.Size1);
			lc4Cutting.Size2 = new LC4Numeric(cuttingResult.Size2);
			AddSections(lc4Cutting, cuttingResult);
			m_result.Cuttings.Add(lc4Cutting);
		}

		private void AddSections(LC4SectionsCollection into, CuttingSectionsCollection sections)
		{
			foreach (CuttingSection section in sections)
			{
				LC4Section lc4Section = ConvertSection(section);
				into.Add(lc4Section);
				AddSections(lc4Section, section);
			}
		}

		private LC4Section ConvertSection(CuttingSection input)
		{
			LC4Section result = m_result.CreateSection();
			switch (input.SectionType)
			{
				case CuttingSectionType.Cut:
					result.SectionType = LC4SectionType.Cut;
					break;
				case CuttingSectionType.Element:
					result.SectionType = LC4SectionType.Detail;
					break;
				case CuttingSectionType.NewLine:
					result.SectionType = LC4SectionType.NewLine;
					break;
				case CuttingSectionType.Remain:
					result.SectionType = LC4SectionType.Remain;
					break;
				case CuttingSectionType.Scrap:
					result.SectionType = LC4SectionType.Scrap;
					break;
			}
			result.Size = new LC4Numeric(input.Size);
			return result;
		}
	}

}
