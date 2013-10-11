/*
 * Конвертация между внутренним форматом и форматом станка lc4
 * 
 * Проблемы:
 * 1. Не сохраняется количество копий раскроев. Причина - неизвестный формат представления этого значения в lc4
 */
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
		public LC4Convertor()
		{
		}

		private void AddSubLanes(Lane into, LinkedList<Section> sections)
		{
			Section prevSection;
			Section nextSection;
			for (LinkedListNode<Section> node = sections.First; node != null; node = node.Next)
			{
				if(node != sections.First)
					prevSection = node.Previous.Value;
				else
					prevSection = null;
				if(node != sections.Last)
					nextSection = node.Next.Value;
				else
					nextSection = null;
				Lane lane = ConvertSection(node.Value, prevSection, nextSection);
				into.Add(lane);
                AddSubLanes(lane, node.Value.NestedSections);
			}
		}

		/*
		 * Предыдущая секция нужна в случае если конвертитуется обрезок, т.к.
		 * его размер должен включать размер реза, который находится перед ним.
		 */
		private Lane ConvertSection(Section input, Section prevSection, Section nextSection)
		{
			Lane result = new Lane();
			result.Size = input.Size;
			switch (input.SectionType)
			{
				case SectionType.Cut:
					result.LaneType = LaneType.Cut;
                    result.SizeType = SizeType.Automatic;
                    break;
				case SectionType.Element:
                    result.LaneType = LaneType.Detail;
                    result.SizeType = SizeType.Changeable;
                    result.Name = DetailNameFixer.Convert(Transliterator.Convert(input.Label));
                    break;
				case SectionType.NewLine:
                    result.LaneType = LaneType.Lane;
                    result.SizeType = SizeType.Changeable;
                    break;
				case SectionType.Remain:
                    result.LaneType = LaneType.Rest;
                    result.SizeType = SizeType.Changeable;
                    break;
				case SectionType.Scrap:
                    result.LaneType = LaneType.Cutoff;
                    result.SizeType = SizeType.Automatic;
					if (prevSection != null && prevSection.SectionType == SectionType.Cut)
						result.Size = input.Size + prevSection.Size;
					if (nextSection != null && nextSection.SectionType == SectionType.Cut)
						result.Size = input.Size + nextSection.Size;
					break;
				case SectionType.Free:
                    result.LaneType = LaneType.Cutoff;
                    result.SizeType = SizeType.Automatic;
                    if (prevSection != null && prevSection.SectionType == SectionType.Cut)
						result.Size = input.Size + prevSection.Size;
					if (nextSection != null && nextSection.SectionType == SectionType.Cut)
						result.Size = input.Size + nextSection.Size;
					break;
			}
			return result;
		}

		public Job Convert(List<CuttingScheme> schemes)
		{
			Job result = new Job();
			Int32 cuttingIndex = 0;
            Dictionary<Sheet, LC4.Sheet> map = new Dictionary<Sheet, LC4.Sheet>();
			foreach (CuttingScheme scheme in schemes)
			{
                Plan plan = new Plan();
                plan.Name = (cuttingIndex + 1).ToString("00000");
                plan.LaneType = LaneType.Plate;
                plan.Size = scheme.Height; // поперечный размер
                plan.Length = scheme.Width; // продольный размер
                plan.SizeType = SizeType.Changeable;
                plan.NurVonVorneAbarbeiten = true;
                plan.TotalAmount = scheme.Repetitions;

                // создаём промежуточную полосу в случае когда первый рез является продольным
                Lane rootLane;
                if (scheme.RootSection.NestedSections.First.Value.CutType == CutType.Horizontal)
                {
                    rootLane = new Lane();
                    rootLane.Size = scheme.Width;
                    rootLane.LaneType = LaneType.Lane;
                    rootLane.SizeType = SizeType.Fixed;
                }
                else
                {
                    rootLane = plan;
                }

                // указываем плиту на которой происходит раскрой
                LC4.Sheet sheet;
                Lage lage = new Lage();
                if (!map.TryGetValue(scheme.Sheet, out sheet))
                {
                    sheet = new LC4.Sheet();
                    // в scheme ширина и высота указывается относительно экрана
                    sheet.Length = scheme.Sheet.Width;
                    sheet.Width = scheme.Sheet.Height;
                    sheet.Thickness = scheme.Sheet.Thickness;
                    sheet.Amount = 0;
                    map.Add(scheme.Sheet, sheet);
                    result.Sheets.Add(sheet);
                }
                lage.Amount = scheme.Repetitions;
                lage.BaseDetail = sheet;
                sheet.Amount += scheme.Repetitions;
                lage.Quality = "";
                plan.Lagen.Add(lage);

                // добавляем вложенные полосы
                AddSubLanes(plan, scheme.RootSection.NestedSections);

                Statistics stat = scheme.CalcStatistics();
				plan.Information.TotalSquare = (double)scheme.Sheet.Width * (double)scheme.Sheet.Height;
				plan.Information.DustSquare = stat.DustSquare;
				plan.Information.ScrapsSquare = stat.ScrapsSquare + stat.UndefinitesSquare;
				plan.Information.ScrapPercent = (plan.Information.DustSquare + plan.Information.ScrapsSquare) / plan.Information.TotalSquare * 100.0;
				plan.Information.DetailsCount = stat.DetailsCount;
				plan.Information.DetailsSquare = stat.DetailsSquare;
				plan.Information.RemainsCount = stat.RemainsCount;
				plan.Information.RemainsSquare = stat.RemainsSquare;

				result.Plans.Add(plan);
				cuttingIndex++;
			}
			return result;
		}
	}

}
