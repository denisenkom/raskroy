using System.Diagnostics;

namespace Denisenko.Cutting
{
    public class Utils
    {
        public static CutType RotateCut(CutType cutType)
        {
            if (cutType == CutType.Horizontal)
            {
                return CutType.Vertical;
            }
            else if (cutType == CutType.Vertical)
            {
                return CutType.Horizontal;
            }
            else
            {
                Debug.Fail("Invalid parameter in function RotateCut");
                return CutType.Undefined;
                /*throw InvalidArgumentException();*/
            }
        }
    }
}
