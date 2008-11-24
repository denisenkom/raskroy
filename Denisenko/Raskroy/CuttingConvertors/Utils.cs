using System;
using System.Collections.Generic;
using System.IO;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

namespace Denisenko.Cutting
{
    class Transliterator
    {
        public static string Convert (string value)
        {
            string intext = "ÀÁÂÃÄÅ¨ÆÇÈÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå¸æçèêëìíîïðñòóôõö÷øùúûüýþÿ";
            string outtext= "ABVGDEEGZIKLMNOPRSTUFHWHHH`Y`EUJabvgdeegziklmnoprstufhchhh`y`euj";
            StringBuilder sb = new StringBuilder();
            foreach (char i in value)
            {
                int index;
                index = intext.IndexOf(i);
                if (index > 0)
                {
                    sb.Append(outtext[index]);
                }
                else
                {
                    sb.Append(i);
                }
            }
            return sb.ToString();
        }
    }
    class DetailNameFixer
    {
        public static string Convert(string value)
        {
            Regex nameRegex = new Regex(@"^Poz\.\s*(?<name>.*) \d+x\d+\s*$");
            Match match = nameRegex.Match(value);
            Console.Out.WriteLine("Converting '" + value + "'");
            if (match.Success)
            {
                Console.Out.WriteLine("...match, result is '" + match.Groups["name"].Value + "'");
                return match.Groups["name"].Value;
            }
            else
            {
                System.Console.Out.WriteLine("...not match");
                return value;
            }
        }
    }
}