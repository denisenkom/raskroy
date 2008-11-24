/* 
 * Корвертация раскроя из экспортируемых базисом dxf файлов во внутренный формат
 * 
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Denisenko.Cutting.Converting
{
    public class BazConvertor
    {
        private CuttingScheme _scheme;
        private LinkedList<Line> _cuts;
        private double _cutterThick;
        private LinkedList<Text> _texts;

        public void Convert(ICollection<CuttingScheme> output, StreamReader tr)
        {
            // сканирование dxf, загрузка линий и текстов
            int typeCode;
            string data;
            while (true)
            {
                typeCode = int.Parse(tr.ReadLine());
                data = tr.ReadLine();
                if (typeCode == 0 && data == "SECTION")
                {
                    typeCode = int.Parse(tr.ReadLine());
                    data = tr.ReadLine();
                    if (typeCode == 2 && data == "ENTITIES")
                    {
                        break;
                    }
                }
            }

            List<Line> lines = new List<Line>();
            _texts = new LinkedList<Text>();

            while (!tr.EndOfStream)
            {
                typeCode = int.Parse(tr.ReadLine());
                data = tr.ReadLine();
                if (typeCode == 0 && data == "LINE")
                {
                    Line line = new Line();
                    line.Read(tr);
                    lines.Add(line);
                }
                else if (typeCode == 0 && data == "TEXT")
                {
                    Text text = new Text();
                    text.Read(tr);
                    _texts.AddLast(text);
                }
            }

            // составляем список резов, выбирая линии со стилем HIDDEN
            LinkedList<Line> buffer = new LinkedList<Line>(lines);
            _cuts = new LinkedList<Line>();
            BazUtils.TakeFrom(buffer, _cuts, BazUtils.CutsPredicate);

            // составляем список прямоугольноков, собирая их из линий
            List<Line> otherLines = new List<Line>();
            LinkedList<Rectangle> rects = new LinkedList<Rectangle>();
            while (buffer.Count > 0)
            {
                Line line1 = buffer.First.Value;
                buffer.RemoveFirst();
                Line line2 = BazUtils.FindContLine(line1, buffer);
                if (line2 == null)
                {
                    otherLines.Add(line1);
                    continue;
                }
                buffer.Remove(line2);
                Line line3 = BazUtils.FindContLine(line2, buffer);
                if (line3 == null)
                {
                    otherLines.Add(line1);
                    otherLines.Add(line2);
                    continue;
                }
                buffer.Remove(line3);
                Line line4 = BazUtils.FindContLine(line2, buffer);
                if (line4 != null)
                {
                    otherLines.Add(line1);
                    otherLines.Add(line2);
                    otherLines.Add(line3);
                    continue;
                }
                buffer.Remove(line4);

                Rectangle rect = new Rectangle();
                rect.LeftBottom.X = Math.Min(line1.P1.X, line2.P2.X);
                rect.LeftBottom.Y = Math.Min(line1.P1.Y, line2.P2.Y);
                rect.RightTop.X = Math.Max(line1.P1.X, line2.P2.X);
                rect.RightTop.Y = Math.Max(line1.P1.Y, line2.P2.Y);
                rects.AddLast(rect);
            }

            BazUtils.BubbleSort<Rectangle>(rects, Rectangle.SquareDescending);
            while (rects.Count > 0)
            {
                // находим прямоугольники листа и его обрезанной части
                Rectangle sheetRect = rects.First.Value;
                rects.RemoveFirst();
                List<Rectangle> internals = new List<Rectangle>();
                BazUtils.TakeFrom<Rectangle>(rects, internals, sheetRect.IsContains);
                if (internals.Count == 0)
                {
                    break;
                }
                Rectangle cutoffRect = internals[0];

                // определяем ширину реза и направление первого реза
                CutMatcher matcher = new CutMatcher();
                CuttingDirection firstCut;
                matcher.Bounds = cutoffRect;
                Line match = BazUtils.Lookup(_cuts, matcher.MatchHorizontalCut);
                if (match == null)
                {
                    match = BazUtils.Lookup(_cuts, matcher.MatchVerticalCut);
                    _cutterThick = (cutoffRect.LeftBottom.Y - match.P1.Y) * 2;
                    firstCut = CuttingDirection.Vertical;
                }
                else
                {
                    _cutterThick = (cutoffRect.LeftBottom.X - match.P1.X) * 2;
                    firstCut = CuttingDirection.Horizontal;
                }

                // заполняем полученные параметры раскроя
                ParametersCollection pars = new ParametersCollection();
                pars.CutterThickness = (decimal)(_cutterThick * 10.0);
                pars.CutOffLeft = (decimal)((cutoffRect.LeftBottom.X - sheetRect.LeftBottom.X) * 10.0);
                pars.CutOffBottom = (decimal)((cutoffRect.LeftBottom.Y - sheetRect.LeftBottom.Y) * 10.0);
                pars.CutOffRight = (decimal)((sheetRect.RightTop.X - cutoffRect.RightTop.X) * 10.0);
                pars.CutOffTop = (decimal)((sheetRect.RightTop.Y - cutoffRect.RightTop.Y) * 10.0);
                _scheme = new CuttingScheme();
                _scheme.Parameters = pars;
                _scheme.Sheet = new Sheet();
                _scheme.Sheet.Thickness = 16;
                _scheme.Height = (decimal)((sheetRect.RightTop.Y - sheetRect.LeftBottom.Y) * 10.0);
                _scheme.Width = (decimal)((sheetRect.RightTop.X - sheetRect.LeftBottom.X) * 10.0);
                _scheme.Sheet.Width = _scheme.Width;
                _scheme.Sheet.Height = _scheme.Height;

                // составляем сам раскрой
                if (firstCut == CuttingDirection.Vertical)
                {
                    CutHorizontalStrip(_scheme.RootSection, cutoffRect);
                }
                else
                {
                    CutVerticalStrip(_scheme.RootSection, cutoffRect);
                }
                
                // получаем количество листов из строчки под раскроем
                List<Text> sheetInfo = new List<Text>();
                TextMatcher textMatcher = new TextMatcher();
                textMatcher.Bounds = sheetRect.HorizStrip(sheetRect.LeftBottom.Y - 30, sheetRect.LeftBottom.Y);
                BazUtils.TakeFrom<Text>(_texts, sheetInfo, textMatcher.IsInside);
                sheetInfo.Sort(Text.PosYAscending);
                string sheetsCountStr = sheetInfo[0].Value;
                int eqPos = sheetsCountStr.LastIndexOf('=');
                _scheme.Repetitions = int.Parse(sheetsCountStr.Substring(eqPos + 1, sheetsCountStr.Length - eqPos - 1));

                output.Add(_scheme);
            }
        }

        void CutVerticalStrip(Section section, Rectangle rect)
        {
            CutMatcher matcher = new CutMatcher();
            matcher.Bounds = rect;
            List<Line> sectionCuts = new List<Line>();
            BazUtils.TakeFrom(_cuts, sectionCuts, matcher.MatchHorizontalCut);
            if (sectionCuts.Count > 0)
            {
                sectionCuts.Sort(BazUtils.HorzCutsComparer);
                double from = rect.LeftBottom.Y;
                Section top = section;
                foreach (Line cut in sectionCuts)
                {
                    Section bottom = _scheme.Cut(top, (decimal)((cut.P1.Y - from - _cutterThick / 2.0) * 10.0), CutType.Horizontal, out top);
                    _scheme.MakeSureEdgeEven(ref bottom, CutType.Horizontal);
                    CutHorizontalStrip(bottom, rect.HorizStrip(from, cut.P1.Y - _cutterThick / 2.0));
                    from = cut.P1.Y + _cutterThick / 2.0;
                }
                if (top != null)
                {
                    CutHorizontalStrip(top, rect.HorizStrip(from, rect.RightTop.Y));
                }
            }
            else // деталь
            {
                Text text = BazUtils.FindText(rect, _texts);
                if (text != null)
                {
                    section.SectionType = SectionType.Element;
                    section.Label = text.Value;
                }
                else
                {
                    section.SectionType = SectionType.Scrap;
                }
            }
        }

        void CutHorizontalStrip(Section section, Rectangle rect)
        {
            CutMatcher matcher = new CutMatcher();
            matcher.Bounds = rect;
            List<Line> sectionCuts = new List<Line>();
            BazUtils.TakeFrom(_cuts, sectionCuts, matcher.MatchVerticalCut);
            if (sectionCuts.Count > 0)
            {
                sectionCuts.Sort(BazUtils.VertCutsComparer);
                double from = rect.LeftBottom.X;
                Section right = section;
                foreach (Line cut in sectionCuts)
                {
                    Section left = _scheme.Cut(right, (decimal)((cut.P1.X - from - _cutterThick / 2.0) * 10.0), CutType.Vertical, out right);
                    //_scheme.MakeSureEdgeEven(ref left, CutType.Vertical);
                    CutVerticalStrip(left, rect.VerticalStrip(from, cut.P1.X - _cutterThick / 2.0));
                    from = cut.P1.X + _cutterThick / 2.0;
                }
                if (right != null)
                {
                    CutVerticalStrip(right, rect.VerticalStrip(from, rect.RightTop.X));
                }
            }
            else
            {
                Text text = BazUtils.FindText(rect, _texts);
                if (text != null)
                {
                    section.SectionType = SectionType.Element;
                    section.Label = text.Value;
                }
                else
                {
                    section.SectionType = SectionType.Scrap;
                }
            }
        }
    }
}
