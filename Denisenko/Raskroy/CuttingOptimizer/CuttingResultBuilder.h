#pragma once

#include "raskroy.h"

namespace Denisenko {
namespace Cutting {

public ref class CuttingResultBuilder
{
public:
	CuttingResultBuilder()
	{
	}

	CuttingResult^ Convert(const Denisenko::Raskroy::t_result& input, Int32 sawThickness, Int32 size1, Int32 size2)
	{
		m_result = gcnew CuttingResult();
		m_sawThickness = sawThickness;
		m_result->Size1 = size1;
		m_result->Size2 = size2;
		Int32 rect[2] = {size1, size2};
		Recursive(input.raskroy, rect, m_result);
		return m_result;
	}

private:
	CuttingResult^ m_result;
	Int32 m_sawThickness;

	void Recursive(const Denisenko::Raskroy::t_raskroy& input, Int32 sizes[], CuttingSectionsCollection^ output)
	{
		CuttingSectionsCollection^ outputLine;
		if(input.cut < sizes[input.s]) // нужно начать новую полосу
		{
			CuttingSection^ newLine = gcnew CuttingSection(CuttingSectionType::NewLine, input.cut);
			outputLine = newLine;
			output->Add(newLine);
		}
		else
		{
			outputLine = output;
		}

		Int32 remain = sizes[!input.s];

		for(UInt32 i = 0; i < input.details.size(); i++)
		{
			for(Int32 j = input.details[i].num; j > 0; j--)
			{
				outputLine->Add(gcnew CuttingSection(CuttingSectionType::Element, input.details[i].size));
				remain -= input.details[i].size;
				if(remain >= m_sawThickness)
				{
					outputLine->Add(gcnew CuttingSection(CuttingSectionType::Cut, m_sawThickness));
					remain -=  m_sawThickness;
				}
				else if(remain > 0)
				{
					outputLine->Add(gcnew CuttingSection(CuttingSectionType::Cut, remain));
					remain = 0;
				}
			}
		}

		if(input.watchRemain() != NULL)
		{
			Int32 newRect[2];
			newRect[input.s] = input.cut;
			newRect[!input.s] = remain;
			Recursive(*input.watchRemain(), newRect, outputLine);
		}
		else
		{
			outputLine->Add(gcnew CuttingSection(CuttingSectionType::Scrap, remain));
		}

		remain = sizes[input.s] - input.cut;
		if(remain > 0) // была сделана новая полоса
		{
			if(remain >= m_sawThickness)
			{
				output->Add(gcnew CuttingSection(CuttingSectionType::Cut, m_sawThickness));
				remain -= m_sawThickness;
			}
			else
			{
				output->Add(gcnew CuttingSection(CuttingSectionType::Cut, remain));
				remain = 0;
			}
		}
		
		if(remain > 0) 
		{
			if(input.watchRecurse() != NULL)
			{
				Int32 newRect[2];
				newRect[input.s] = remain;
				newRect[!input.s] = sizes[!input.s];
				Recursive(*input.watchRecurse(), newRect, output);
			}
			else
			{
				output->Add(gcnew CuttingSection(CuttingSectionType::Scrap, remain));
			}
		}
	}
};

}
}