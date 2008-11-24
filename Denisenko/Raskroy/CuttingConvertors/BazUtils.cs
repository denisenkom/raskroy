using System;
using System.Collections.Generic;
using System.IO;
using System.Globalization;
using System.Text;

namespace Denisenko.Cutting
{
    struct Point
    {
        public double X;
        public double Y;

        public override bool Equals(Object objRhs)
        {
            if (!(objRhs is Point))
            {
                return false;
            }
            Point rhs = (Point)objRhs;
            return X == rhs.X && Y == rhs.Y;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        static public bool operator ==(Point lhs, Point rhs)
        {
            return lhs.X == rhs.X && lhs.Y == rhs.Y;
        }

        static public bool operator !=(Point lhs, Point rhs)
        {
            return lhs.X != rhs.X || lhs.Y != rhs.Y;
        }

        public override string ToString()
        {
            StringBuilder bldr = new StringBuilder();
            bldr.AppendFormat("({0};{1})", X, Y);
            return bldr.ToString();
        }
    }

    class Line
    {
        public string Layer;
        public string LineType;
        public Point P1;
        public Point P2;

        public void Read(TextReader tr)
        {
            int typeCode;
            typeCode = int.Parse(tr.ReadLine());
            Layer = tr.ReadLine();

            typeCode = int.Parse(tr.ReadLine());
            LineType = tr.ReadLine();

            typeCode = int.Parse(tr.ReadLine());
            tr.ReadLine(); // skip

            NumberFormatInfo nfi = new NumberFormatInfo();
            nfi.CurrencyDecimalSeparator = ".";

            typeCode = int.Parse(tr.ReadLine());
            P1.X = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            P1.Y = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            P2.X = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            P2.Y = double.Parse(tr.ReadLine(), nfi);
        }

        public override string ToString()
        {
            return P1.ToString() + "-" + P2.ToString() + "-" + LineType;
        }
    }

    class Text
    {
        public string Layer;
        public string LineType;
        public Point Center;
        public double TextHeight;
        public double XScale;
        public double Angle;
        public string Value;

        public void Read(TextReader tr)
        {
            int typeCode;
            typeCode = int.Parse(tr.ReadLine());
            Layer = tr.ReadLine();

            typeCode = int.Parse(tr.ReadLine());
            LineType = tr.ReadLine();

            typeCode = int.Parse(tr.ReadLine());
            tr.ReadLine(); // skip

            NumberFormatInfo nfi = new NumberFormatInfo();
            nfi.CurrencyDecimalSeparator = ".";

            typeCode = int.Parse(tr.ReadLine());
            Center.X = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            Center.Y = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            TextHeight = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            XScale = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            Angle = double.Parse(tr.ReadLine(), nfi);

            typeCode = int.Parse(tr.ReadLine());
            tr.ReadLine(); // skip

            typeCode = int.Parse(tr.ReadLine());
            Value = tr.ReadLine(); // skip
        }

        public static int PosYAscending(Text rhs, Text lhs)
        {
            double delta = rhs.Center.Y - lhs.Center.Y;
            if (delta == 0.0)
            {
                return 0;
            }
            else if (delta > 0.0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        public static int PosYDescending(Text rhs, Text lhs)
        {
            double delta = lhs.Center.Y - rhs.Center.Y;
            if (delta == 0.0)
            {
                return 0;
            }
            else if (delta > 0.0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }

    struct Rectangle
    {
        public Point LeftBottom;
        public Point RightTop;

        public Rectangle(double x1, double x2, double y1, double y2)
        {
            LeftBottom.X = x1;
            LeftBottom.Y = y1;
            RightTop.X = x2;
            RightTop.Y = y2;
        }

        public double Square()
        {
            return RightTop.X * RightTop.Y + LeftBottom.X * LeftBottom.Y - RightTop.X * LeftBottom.Y - RightTop.Y * LeftBottom.X;
            //return (RightTop.X - LeftBottom.X) * (RightTop.Y - LeftBottom.Y);
        }

        public Rectangle VerticalStrip(double begin, double end)
        {
            Rectangle strip;
            strip.LeftBottom.X = begin;
            strip.LeftBottom.Y = LeftBottom.Y;
            strip.RightTop.X = end;
            strip.RightTop.Y = RightTop.Y;
            return strip;
        }

        public Rectangle HorizStrip(double begin, double end)
        {
            Rectangle strip;
            strip.LeftBottom.X = LeftBottom.X;
            strip.LeftBottom.Y = begin;
            strip.RightTop.X = RightTop.X;
            strip.RightTop.Y = end;
            return strip;
        }

        public override string ToString()
        {
            return LeftBottom.ToString() + "-" + RightTop.ToString() + " (" + Square() + ")";
        }

        public bool IsContains(Point pt)
        {
            return pt.X >= LeftBottom.X && pt.X <= RightTop.X && pt.Y >= LeftBottom.Y && pt.Y <= RightTop.Y;
        }

        public bool IsContains(Rectangle rect)
        {
            return IsContains(rect.LeftBottom) && IsContains(rect.RightTop);
        }

        public static int SquareAscending(Rectangle rhs, Rectangle lhs)
        {
            double squareDelta = rhs.Square() - lhs.Square();
            if (squareDelta == 0)
            {
                return 0;
            }
            else if (squareDelta > 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        public static int SquareDescending(Rectangle rhs, Rectangle lhs)
        {
            double sq1 = rhs.Square();
            double sq2 = lhs.Square();
            double squareDelta = sq1 - sq2;
            double t = Math.Pow(2.0, Math.Truncate(Math.Log(Math.Max(sq1, sq2), 2.0)) + 1 + 5 /*округляем 5 младших разрядов т.к. они не точны*/);
            squareDelta = squareDelta + t;
            squareDelta = squareDelta - t;
            if (squareDelta == 0)
            {
                return 0;
            }
            else if (squareDelta > 0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }

    enum CuttingDirection { Horizontal, Vertical }

    class CutMatcher
    {
        public Rectangle Bounds;

        public bool MatchVerticalCut(Line cut)
        {
            return cut.P1.X == cut.P2.X && cut.P1.Y < Bounds.LeftBottom.Y && cut.P2.Y > Bounds.RightTop.Y && cut.P1.X >= Bounds.LeftBottom.X && cut.P1.X <= Bounds.RightTop.X;
        }

        public bool MatchHorizontalCut(Line cut)
        {
            return cut.P1.Y == cut.P2.Y && cut.P1.X < Bounds.LeftBottom.X && cut.P2.X > Bounds.RightTop.X && cut.P1.Y >= Bounds.LeftBottom.Y && cut.P1.Y <= Bounds.RightTop.Y;
        }
    }

    class TextMatcher
    {
        public Rectangle Bounds;

        public bool IsInside(Text text)
        {
            return Bounds.IsContains(text.Center);
        }
    }

    class BazUtils
    {
        public static Line Lookup(ICollection<Line> coll, Predicate<Line> predicate)
        {
            foreach (Line line in coll)
            {
                if (predicate(line))
                {
                    return line;
                }
            }
            return null;
        }

        public static void TakeFrom<T>(LinkedList<T> from, ICollection<T> to, Predicate<T> predicate)
        {
            for (LinkedListNode<T> node = from.First; node != null; )
            {
                if (predicate(node.Value))
                {
                    to.Add(node.Value);
                    LinkedListNode<T> nextNode = node.Next;
                    from.Remove(node);
                    node = nextNode;
                }
                else
                {
                    node = node.Next;
                }
            }
        }

        public static bool CutsPredicate(Line line)
        {
            return line.LineType == "HIDDEN";
        }

        public static int VertCutsComparer(Line lhs, Line rhs)
        {
            double delta = rhs.P1.X - lhs.P1.X;
            if (delta == 0)
            {
                return 0;
            }
            else if (delta > 0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        public static int HorzCutsComparer(Line lhs, Line rhs)
        {
            double delta = rhs.P1.Y - lhs.P1.Y;
            if (delta == 0)
            {
                return 0;
            }
            else if (delta > 0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        public static Line FindContLine(Line from, IEnumerable<Line> lines)
        {
            foreach (Line line in lines)
            {
                if (from.P2 == line.P1)
                {
                    return line;
                }
                else if (from.P2 == line.P2)
                {
                    Point t = line.P1;
                    line.P1 = line.P2;
                    line.P2 = t;
                    return line;
                }
            }
            return null;
        }

        public static Text FindText(Rectangle rect, ICollection<Text> texts)
        {
            foreach (Text text in texts)
            {
                if (rect.IsContains(text.Center))
                {
                    return text;
                }
            }
            return null;
        }

        public static void BubbleSort<T>(LinkedList<T> list, Comparison<T> cmp)
        {
            LinkedListNode<T> sequenced = null;
            LinkedListNode<T> lastSequenced;
            do
            {
                lastSequenced = null;
                for (LinkedListNode<T> node = list.First; node.Next != sequenced; node = node.Next)
                {
                    if (cmp(node.Value, node.Next.Value) > 0)
                    {
                        T t = node.Next.Value;
                        node.Next.Value = node.Value;
                        node.Value = t;
                        lastSequenced = node.Next;
                    }
                }
                sequenced = lastSequenced;
            }
            while (lastSequenced != null);
        }
    }
}
