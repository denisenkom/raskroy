#pragma once

#include "raskroy.h"

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

	CuttingScheme^ Convert(const Denisenko::Raskroy::t_result& input, ParametersCollection^ parameters, Decimal size1, Decimal size2)
	{
		m_parameters = parameters;
		m_result = gcnew CuttingScheme(
			FromScaled(input.sheet->Rect.Length) + parameters->CutOffLeft + parameters->CutOffRight,
			FromScaled(input.sheet->Rect.Width) + parameters->CutOffBottom + parameters->CutOffTop,
			parameters);
		CutType cutType = input.raskroy.s == 0 ? CutType::Vertical : CutType::Horizontal;

		Recursive(input.raskroy, cutType, m_result->RootSection);
		return m_result;
	}

private:
	CuttingScheme^ m_result;
	ParametersCollection^ m_parameters;

	void Recursive(const Denisenko::Raskroy::t_raskroy& input, CutType cutType, Section^ output)
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
				m_result->Cut(detailsLine, FromScaled(input.cut), cutType, detailsLine);
				AddDetails(input.details, detailsLine, CuttingScheme::Rotate(cutType));
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

	Decimal GetDetailsLength(const Raskroy::t_raskroy::t_details& details)
	{
		Decimal result;
		for(UInt32 i = 0; i < details.size(); i++)
		{
			result += FromScaled(details[i].size + ToScaled(m_parameters->CutterThickness)) * details[i].num;
		}
		result -= m_parameters->CutterThickness;
		return result;
	}

	Section^ AddDetails(const Raskroy::t_raskroy::t_details& details, Section^ output, CutType cutType)
	{
		Section^ result = output;
		for(UInt32 i = 0; i < details.size(); i++)
		{
			for(Int32 j = details[i].num; j > 0; j--)
			{
				Section^ partSection = m_result->Cut(result, FromScaled(details[i].size), cutType, result);
				m_result->MarkAsPart(partSection);
			}
		}
		return result;
	}
};

}
}