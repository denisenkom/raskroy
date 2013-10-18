using System;
using System.Collections.Generic;
using Denisenko.Cutting;

namespace Denisenko.Cutting.Optimizing {

public class CuttingResultBuilder
{
	public CuttingResultBuilder()
	{
	}

	unsafe public void LoadSections(_Layout * input, CuttingScheme output)
	{
		m_result = output;
		Recursive(input, output.RootSection);
	}

	private CuttingScheme m_result;

	unsafe private void Recursive(_Layout * input, Section output)
	{
        CutType cutType = input->along == 0 ? CutType.Vertical : CutType.Horizontal;
		m_result.MakeSureEdgeEven(ref output, cutType);

        for (uint i = 0; i < (uint)input->num_elements; i++)
        {
            if (input->elements[i].type == (int)ElementType.Cut)
                continue;
            else if (input->elements[i].type == (int)ElementType.Remain)
                continue;
            var this_sec = m_result.Cut(output, _GuillotineApi.FromScaled(input->elements[i].size), cutType, out output);
            if (input->elements[i].type == (int)ElementType.Rect)
            {
                m_result.MarkAsPart(this_sec);
            }
            else if (input->elements[i].type == (int)ElementType.SubLayout)
            {
                Recursive(input->elements[i].layout, this_sec);
            }
        }
	}
};

}