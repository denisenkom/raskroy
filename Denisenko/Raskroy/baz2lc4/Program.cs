using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Denisenko.Cutting.Converting;
using Denisenko.Cutting.LC4;

namespace Denisenko.Cutting
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                Console.WriteLine("baz2lc4.exe <infile.dxf> [...]");
                Environment.Exit(0);
            }

            List<CuttingScheme> schemes = new List<CuttingScheme>();
            BazConvertor cvt = new BazConvertor();
            foreach (string infile in args)
            {
                using (FileStream stm = new FileStream(infile, FileMode.Open, FileAccess.Read))
                {
                    StreamReader tr = new StreamReader(stm, Encoding.Default);
                    cvt.Convert(schemes, tr);
                }
            }
            LC4Convertor lc4cvt = new LC4Convertor();
            Job job = lc4cvt.Convert(schemes);
            job.Name = Path.GetFileNameWithoutExtension(args[0]);
            string outlc4 = Path.ChangeExtension(args[0], ".lc4");
            job.SaveLC4(outlc4, true);
            //string outxml = Path.ChangeExtension(infile, ".xml");
            //job.Serialize(outxml);
        }
    }
}
