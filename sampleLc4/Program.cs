using System;
using System.Collections.Generic;
using System.Text;
using Denisenko;
using Denisenko.Cutting;
using Denisenko.Cutting.Converting;
using Denisenko.Cutting.LC4;

namespace sampleLc4
{
    class Program
    {
        static void Test1()
        {
            /*Job job = new Job();
            job.Name = "job";
            job.Remarks = "my job";

            LC4.Sheet sheet = new LC4.Sheet();
            sheet.Amount = 50;
            sheet.Length = 524;
            sheet.Width = 524;
            sheet.Thickness = 19;
            sheet.Name = "BrdCode";
            sheet.Material = "MatCode";
            job.Sheets.Add(sheet);

            Plan plan = new Plan();
            plan.Name = "myplan";
            plan.Remarks = "my plan remarks";
            plan.LaneType = LaneType.Plate;
            plan.SizeType = SizeType.Changeable;
            plan.Copies = 1;
            plan.IsCopy = false;
            plan.Size = 524;
            plan.Length = 524;
            plan.TotalAmount = 50;
            plan.StackAmount = 1;

            Lage lage = new Lage();
            lage.Amount = 50;
            lage.Postforming = false;
            lage.Quality = "";
            lage.IsFinishPart = false;
            lage.BaseDetail = sheet;
            plan.Lagen.Add(lage);

            Lane lane1 = new Lane();
            lane1.LaneType = LaneType.Lane;
            lane1.Size = 524;
            plan.Add(lane1);

            Lane cutoff1 = new Lane();
            cutoff1.LaneType = LaneType.Cutoff;
            cutoff1.Size = 12;
            cutoff1.SizeType = SizeType.Automatic;
            lane1.Add(cutoff1);

            Lane cut1 = new Lane();
            cut1.LaneType = LaneType.Cut;
            cut1.Size = 4.5M;
            cut1.SizeType = SizeType.Automatic;
            lane1.Add(cut1);

            Lane lane2 = new Lane();
            lane2.LaneType = LaneType.Lane;
            lane2.Size = 500;
            lane2.SizeType = SizeType.Changeable;
            lane1.Add(lane2);

            Lane cut2 = new Lane();
            cut2.LaneType = LaneType.Cut;
            cut2.Size = 4.5M;
            cut2.SizeType = SizeType.Automatic;
            lane1.Add(cut2);

            Lane cutoff2 = new Lane();
            cutoff2.LaneType = LaneType.Cutoff;
            cutoff2.Size = 12;
            cutoff2.SizeType = SizeType.Automatic;
            lane1.Add(cutoff2);

            job.Plans.Add(plan);

            job.SaveLC4("job.lc4", true);*/
        }

        static void Test2()
        {
            Denisenko.Cutting.Sheet sheet = new Denisenko.Cutting.Sheet();
            sheet.Height = 1225;
            sheet.Width = 1830;
            sheet.Thickness = 16;

            CuttingScheme scheme = new CuttingScheme();
            scheme.Parameters = new ParametersCollection();
            scheme.Parameters.CutOffBottom = 15;
            scheme.Parameters.CutOffLeft = 15;
            scheme.Parameters.CutOffRight = 15;
            scheme.Parameters.CutOffTop = 15;
            scheme.Parameters.CutterThickness = 5;
            scheme.Sheet = sheet;
            Section right;
            Section top;
            Section lane;
            lane = scheme.Cut(scheme.RootSection, 950, CutType.Vertical, out right);
            scheme.Cut(lane, 290, CutType.Horizontal, out top);
            scheme.Cut(top, 290, CutType.Horizontal, out top);
            lane = scheme.Cut(top, 285, CutType.Horizontal, out top);
            scheme.Cut(lane, 720, CutType.Vertical, out right);
            lane = scheme.Cut(top, 790, CutType.Vertical, out right);

            LC4Convertor cvtr = new LC4Convertor();
            Job job = cvtr.Convert(new List<CuttingScheme>(new CuttingScheme[] { scheme }));
            job.Name = "job2";
            job.SaveLC4("job2.lc4", true);
        }

        static void Test3()
        {
            Job job = new Job();
            job.Name = "job";

            Denisenko.Cutting.LC4.Sheet sheet = new Denisenko.Cutting.LC4.Sheet();
            sheet.Amount = 1;
            sheet.Length = 2440;
            sheet.Width = 1830;
            sheet.Thickness = 16;
            job.Sheets.Add(sheet);

            Plan plan = new Plan();
            plan.Name = "00001";
            plan.LaneType = LaneType.Plate;
            plan.SizeType = SizeType.Changeable;
            plan.Copies = 1;
            plan.IsCopy = false;
            plan.Size = 1830;
            plan.Length = 2440;
            plan.TotalAmount = 50;
            plan.StackAmount = 1;

            Lage lage = new Lage();
            lage.Amount = 1;
            lage.Postforming = false;
            lage.Quality = "";
            lage.IsFinishPart = false;
            lage.BaseDetail = sheet;
            plan.Lagen.Add(lage);

            Lane cutoff1 = new Lane();
            cutoff1.LaneType = LaneType.Cutoff;
            cutoff1.Size = 20;
            cutoff1.SizeType = SizeType.Automatic;
            plan.Add(cutoff1);

            Lane cut1 = new Lane();
            cut1.LaneType = LaneType.Cut;
            cut1.Size = 4;
            cut1.SizeType = SizeType.Automatic;
            plan.Add(cut1);

            Lane lane1 = new Lane();
            lane1.LaneType = LaneType.Lane;
            lane1.Size = 980;
            lane1.SizeType = SizeType.Changeable;
            plan.Add(lane1);

            Lane cutoff3 = new Lane();
            cutoff3.LaneType = LaneType.Cutoff;
            cutoff3.Size = 20;
            cutoff3.SizeType = SizeType.Automatic;
            lane1.Add(cutoff3);

            Lane cut3 = new Lane();
            cut3.LaneType = LaneType.Cut;
            cut3.Size = 4;
            cut3.SizeType = SizeType.Automatic;
            lane1.Add(cut3);

            Lane detail = new Lane();
            detail.LaneType = LaneType.Detail;
            detail.Size = 580;
            detail.SizeType = SizeType.Changeable;
            lane1.Add(detail);

            Lane cut4 = new Lane();
            cut4.LaneType = LaneType.Cut;
            cut4.Size = 4;
            cut4.SizeType = SizeType.Automatic;
            lane1.Add(cut4);

            Lane cutoff4 = new Lane();
            cutoff4.LaneType = LaneType.Cutoff;
            cutoff4.Size = 1230;
            cutoff4.SizeType = SizeType.Automatic;
            lane1.Add(cutoff4);

            Lane cut2 = new Lane();
            cut2.LaneType = LaneType.Cut;
            cut2.Size = 4;
            cut2.SizeType = SizeType.Automatic;
            plan.Add(cut2);

            Lane cutoff2 = new Lane();
            cutoff2.LaneType = LaneType.Cutoff;
            cutoff2.Size = 1440;
            cutoff2.SizeType = SizeType.Automatic;
            plan.Add(cutoff2);

            job.Plans.Add(plan);

            job.SaveLC4("job.lc4", true);
        }

        static void Main(string[] args)
        {
            Test3();
        }
    }
}
