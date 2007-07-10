using System;
using System.Collections.Generic;
using System.Text;
using Denisenko.Cutting.LC4;

namespace lc4Dump
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = args[0];
            Job job = Job.LoadLC4(filename);
            job.SaveLC4(filename, true);
            //job.Serialize(filename + ".xml");
        }
    }
}
