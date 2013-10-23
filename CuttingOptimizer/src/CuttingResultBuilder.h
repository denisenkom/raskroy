#pragma once

#include "Raskroy.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace Denisenko::Cutting;

namespace Denisenko {
namespace Cutting {

Decimal FromScaled(Int64 scaled)
{
	return Decimal(scaled) / 1000;
}

Int64 ToScaled(Decimal value)
{
	return Decimal::ToInt64(value * 1000);
}

public ref class CuttingResultBuilder
{
public:
	CuttingResultBuilder()
	{
	}

	void LoadSections(const Denisenko::Raskroy::OldLayoutResult& input, ParametersCollection^ parameters, CuttingScheme^ output)
	{
		m_result = output;
		m_parameters = parameters;
		CutType cutType = input.s == 0 ? CutType::Vertical : CutType::Horizontal;
		Recursive(input, cutType, output->RootSection);
	}

private:
	CuttingScheme^ m_result;
	ParametersCollection^ m_parameters;

	void Recursive(const Denisenko::Raskroy::OldLayoutResult& input, CutType cutType, Section^ output)
	{
		m_result->MakeSureEdgeEven(output, cutType);

		Decimal lineWidth = (FromScaled(input.cut) + m_parameters->CutterThickness) * input.kratnostj - m_parameters->CutterThickness;
		Section^ rightLine;
		Section^ leftLine = m_result->Cut(output, lineWidth, cutType, rightLine);
		Section^ bottomLine;
		m_result->MakeSureEdgeEven(leftLine, CuttingScheme::Rotate(cutType));
		if(input.kratnostj > 1)
		{
			Section^ detailsLine = m_result->Cut(leftLine, GetDetailsLength(input.details), CuttingScheme::Rotate(cutType), bottomLine);
			for(Int32 i = input.kratnostj; i > 0; i--) {
				Section^ detailsRemain;
				detailsLine = m_result->Cut(detailsLine, FromScaled(input.cut), cutType, detailsRemain);
				AddDetails(input.details, detailsLine, CuttingScheme::Rotate(cutType));
				detailsLine = detailsRemain;
			}
		}
		else
		{
			bottomLine = AddDetails(input.details, leftLine, CuttingScheme::Rotate(cutType));
		}

		// Прицепляем нижнюю часть, если есть
		if(input.watchRemain() != NULL)
		{
			CutType newCutType = input.watchRemain()->s != input.s ? CuttingScheme::Rotate(cutType) : cutType;
			Recursive(*input.watchRemain(), newCutType, bottomLine);
		}

		// Прицепляем правую часть, если есть
		if(input.watchRecurse() != NULL)
		{
			CutType newCutType = input.watchRecurse()->s != input.s ? CuttingScheme::Rotate(cutType) : cutType;
			Recursive(*input.watchRecurse(), newCutType, rightLine);
		}
	}

	Decimal GetDetailsLength(const Raskroy::OldLayoutResult::Details& details)
	{
		Decimal result;
		for(Raskroy::OldLayoutResult::Details::const_iterator i = details.begin();
			i != details.end(); i++)
		{
			result += FromScaled(i->size + ToScaled(m_parameters->CutterThickness)) *
				i->num;
		}
		result -= m_parameters->CutterThickness;
		return result;
	}

	Section^ AddDetails(const Raskroy::OldLayoutResult::Details& details, Section^ output, CutType cutType)
	{
		Section^ result = output;
		for(Raskroy::OldLayoutResult::Details::const_iterator i = details.begin();
			i != details.end(); i++)
		{
			for(Int32 j = i->num; j > 0; j--)
			{
				Section^ partSection = m_result->Cut(result, FromScaled(i->size),
					cutType, result);
				m_result->MarkAsPart(partSection);
			}
		}
		return result;
	}
};

}
}
