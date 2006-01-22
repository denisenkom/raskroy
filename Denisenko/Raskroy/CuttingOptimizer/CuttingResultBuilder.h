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

	CuttingScheme^ Convert(const Denisenko::Raskroy::t_result& input, ParametersCollection^ parameters, Size size1, Size size2)
	{
		m_result = gcnew CuttingScheme();
		m_parameters = parameters;
		array<Size>^ rect = gcnew array<Size>(2);
		rect[0] = size1;
		rect[1] = size2;
		m_result->Width = rect[input.raskroy.s] + parameters->CutOffLeft + parameters->CutOffRight;
		m_result->Height = rect[!input.raskroy.s] + parameters->CutOffBottom + parameters->CutOffTop;

		Recursive(input.raskroy, rect, m_result);
		return m_result;
	}

private:
	CuttingScheme^ m_result;
	ParametersCollection^ m_parameters;

	void Recursive(const Denisenko::Raskroy::t_raskroy& input, array<Size>^ sizes, CuttingSectionsCollection^ output)
	{
		Size width = sizes[input.s];
		Size height = sizes[!input.s];

		CuttingSectionsCollection^ leftLine;
		Size lineWidth = (Size::FromScaled(input.cut) + m_parameters->CutterThickness) * input.kratnostj - m_parameters->CutterThickness;
		if(lineWidth < width) // нужно начать новую полосу
		{
			CuttingSection^ newLine = gcnew CuttingSection(CuttingSectionType::NewLine, lineWidth);
			leftLine = newLine;
			output->Add(newLine);
		}
		else
		{
			leftLine = output;
		}

		Size detailsSize;
		if(input.kratnostj > 1)
		{
			CuttingSection^ horizontalLine = gcnew CuttingSection(CuttingSectionType::NewLine);
			CuttingSection^ detailsRefLine = gcnew CuttingSection(CuttingSectionType::NewLine, Size::FromScaled(input.cut));
			detailsSize = AddDetails(input.details, detailsRefLine);
			horizontalLine->Size = detailsSize;
			for(Int32 i = input.kratnostj; i > 0; i--) {
				horizontalLine->Add(detailsRefLine->Clone());
				if(i > 1)
					horizontalLine->Add(gcnew CuttingSection(CuttingSectionType::Cut, m_parameters->CutterThickness));
			}
			leftLine->Add(horizontalLine);
		}
		else
		{
			detailsSize = AddDetails(input.details, leftLine);
		}

		// ѕрицепл€ем нижнюю часть, если есть
		if(height - detailsSize > Size::Zero)
		{
			leftLine->Add(gcnew CuttingSection(CuttingSectionType::Cut, Size::Min(m_parameters->CutterThickness, height - detailsSize)));

			if(height - detailsSize - m_parameters->CutterThickness > Size::Zero)
			{
				if(input.watchRemain() != NULL)
				{
					array<Size>^ newRect = gcnew array<Size>(2);
					newRect[input.s] = lineWidth;
					newRect[!input.s] = height - detailsSize - m_parameters->CutterThickness;
					if(input.watchRemain()->s == input.s)
					{
						CuttingSection^ bottomLine = gcnew CuttingSection(CuttingSectionType::NewLine, height - detailsSize - m_parameters->CutterThickness);
						Recursive(*input.watchRemain(), newRect, bottomLine);
						leftLine->Add(bottomLine);
					}
					else
					{
						Recursive(*input.watchRemain(), newRect, leftLine);
					}
				}
				else
				{
					leftLine->Add(gcnew CuttingSection(CuttingSectionType::Scrap, height - detailsSize - m_parameters->CutterThickness));
				}
			}
		}

		// ѕрицепл€ем правую часть, если есть
		if(width - lineWidth > Size::Zero) // была сделана нова€ полоса
		{
			output->Add(gcnew CuttingSection(CuttingSectionType::Cut, Size::Min(m_parameters->CutterThickness, width - lineWidth)));
		
			if(width - lineWidth - m_parameters->CutterThickness > Size::Zero)
			{
				if(input.watchRecurse() != NULL)
				{
					array<Size>^ newRect = gcnew array<Size>(2);
					newRect[input.s] = width - lineWidth - m_parameters->CutterThickness;
					newRect[!input.s] = height;
					Recursive(*input.watchRecurse(), newRect, output);
				}
				else
				{
					output->Add(gcnew CuttingSection(CuttingSectionType::Scrap, width - lineWidth - m_parameters->CutterThickness));
				}
			}
		}
	}

	Size AddDetails(const Raskroy::t_raskroy::t_details& details, CuttingSectionsCollection^ output)
	{
		Size result;
		for(UInt32 i = 0; i < details.size(); i++)
		{
			for(Int32 j = details[i].num; j > 0; j--)
			{
				output->Add(gcnew CuttingSection(CuttingSectionType::Element, Size::FromScaled(details[i].size)));
				result.Scaled += details[i].size;
				if(j > 1 || i < details.size() - 1)
				{
					output->Add(gcnew CuttingSection(CuttingSectionType::Cut, m_parameters->CutterThickness));
					result += m_parameters->CutterThickness;
				}
			}
		}
		return result;
	}
};

}
}