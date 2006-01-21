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

	CuttingResult^ Convert(const Denisenko::Raskroy::t_result& input, Size sawThickness, Size size1, Size size2)
	{
		m_result = gcnew CuttingResult();
		m_sawThickness = sawThickness;
		m_result->Size1 = size1;
		m_result->Size2 = size2;
		array<Size>^ rect = gcnew array<Size>(2);
		rect[0] = size1;
		rect[1] = size2;
		Recursive(input.raskroy, rect, m_result);
		return m_result;
	}

private:
	CuttingResult^ m_result;
	Size m_sawThickness;

	void Recursive(const Denisenko::Raskroy::t_raskroy& input, array<Size>^ sizes, CuttingSectionsCollection^ output)
	{
		CuttingSectionsCollection^ outputLine;
		if(input.cut < sizes[input.s].Scaled) // нужно начать новую полосу
		{
			CuttingSection^ newLine = gcnew CuttingSection(CuttingSectionType::NewLine, Size::FromScaled(input.cut));
			outputLine = newLine;
			output->Add(newLine);
		}
		else
		{
			outputLine = output;
		}

		Size remain = sizes[!input.s];

		for(UInt32 i = 0; i < input.details.size(); i++)
		{
			for(Int32 j = input.details[i].num; j > 0; j--)
			{
				outputLine->Add(gcnew CuttingSection(CuttingSectionType::Element, Size::FromScaled(input.details[i].size)));
				remain.Scaled -= input.details[i].size;
				if(remain >= m_sawThickness)
				{
					outputLine->Add(gcnew CuttingSection(CuttingSectionType::Cut, m_sawThickness));
					remain -=  m_sawThickness;
				}
				else if(remain > Size(0))
				{
					outputLine->Add(gcnew CuttingSection(CuttingSectionType::Cut, remain));
					remain = Size::Zero;
				}
			}
		}

		if(input.watchRemain() != NULL)
		{
			array<Size>^ newRect = gcnew array<Size>(2);
			newRect[input.s] = Size::FromScaled(input.cut);
			newRect[!input.s] = remain;
			Recursive(*input.watchRemain(), newRect, outputLine);
		}
		else
		{
			outputLine->Add(gcnew CuttingSection(CuttingSectionType::Scrap, remain));
		}

		remain = sizes[input.s] - Size::FromScaled(input.cut);
		if(remain > Size::Zero) // была сделана новая полоса
		{
			if(remain >= m_sawThickness)
			{
				output->Add(gcnew CuttingSection(CuttingSectionType::Cut, m_sawThickness));
				remain -= m_sawThickness;
			}
			else
			{
				output->Add(gcnew CuttingSection(CuttingSectionType::Cut, remain));
				remain = Size::Zero;
			}
		}
		
		if(remain > Size::Zero) 
		{
			if(input.watchRecurse() != NULL)
			{
				array<Size>^ newRect = gcnew array<Size>(2);
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