#include "stdafx.h"
#include "errors.h"
#include "Raskroy.h"

using namespace std;

namespace Denisenko {
namespace Raskroy {

/*void Raskroy::RemoveExostedSizes(void)
{
	for (unsigned s = 0; s <= 1; s++)
	{
		Sizes::iterator pSize = m_sizes[s].begin();
		while (pSize != m_sourceSizes[s].end())
		{
			OtherSizes::iterator pOtherSize = pSize->OtherSizes.begin();
			while (pOtherSize != pSize->OtherSizes.end())
			{
				if (m_remains[pOtherSize->Offset] == 0)
				{
					pSize->OtherSizes.erase(pOtherSize);
					pOtherSize = pSize->OtherSizes.begin();
				}
				else
					pOtherSize++;
			}
			if (pSize->OtherSizes.empty())
			{
				m_sourceSizes[s].erase(pSize);
				pSize = m_sourceSizes[s].begin();
			}
			else
			{
				pSize->OtherSizes.SetMin();
				pSize++;
			}
		}
	}
}*/

void Raskroy::SubstractPartsAmounts(const Amounts& amounts)
{
	Amounts workingAmounts(amounts);
	for(Sizes::iterator i = m_sizes[0].begin(); i != m_sizes[0].end(); i++)
	{
		for(OtherSizes::iterator j = i->OtherSizes.begin(); j != i->OtherSizes.end(); j++)
		{
			if(workingAmounts[j->Offset] != 0)
			{
				vector<Parts::iterator> parts = m_parts.FindAll(i->Value, j->Value);
				unsigned pi = 0;
				vector<Parts::iterator> partsToRemove;
				while(workingAmounts[j->Offset] != 0)
				{
					unsigned substracting = min(workingAmounts[j->Offset], parts[pi]->Amount);
					parts[pi]->Amount -= substracting;
					if(parts[pi]->Amount == 0)
					{
						partsToRemove.push_back(parts[pi]);
					}
					workingAmounts[j->Offset] -= substracting;
					pi++;
				}
				m_parts.Remove(partsToRemove);
			}
		}
	}
}

double Mean(const vector<double>& data)
{
	double sum = 0;
	for(vector<double>::const_iterator i = data.begin(); i != data.end(); i++)
	{
		sum += *i;
	}
	return sum / (double)(data.size());
}

int Raskroy::CalcOptimalSizesCount(scalar sheetSize, const Sizes& sizes)
{
	vector<double> relSizes;
	for(Sizes::const_iterator i = sizes.begin(); i != sizes.end(); i++)
	{
		relSizes.push_back((double)i->Value / (double)sheetSize);
	}
	double meanRelSize = Mean(relSizes);
	double paramA = (1.0 - 0.3)*8.0;/*16.0;*/
	return (int)(paramA / (1.0 - meanRelSize));
}

void Raskroy::BalanceWorkingSet(Rect sheetSize)
{
	Parts workingParts(m_parts);
	for(;;)
	{
		MakeSizesAndRemainsList(workingParts);
		if((int)m_sizes[0].size() + (int)m_sizes[1].size() <=
			CalcOptimalSizesCount(sheetSize.Size[0], m_sizes[0]) + 
			CalcOptimalSizesCount(sheetSize.Size[1], m_sizes[1]))
		{
			return;
		}
		workingParts.erase(workingParts.begin() + rand() % workingParts.size());
	}
}

void Raskroy::MakeSizesAndRemainsList(Parts &parts)
{
	m_remains.clear();
	for (int s = 0; s <= 1; s++)
	{
		m_sizes[s].clear();
		for (Parts::iterator pPart = parts.begin(); pPart != parts.end(); pPart++)
			m_sizes[s].AddPart(*pPart, s, m_remains);

		// Сортировка размеров
		sort(m_sizes[s].begin(), m_sizes[s].end());
		for (Sizes::iterator pSize = m_sizes[s].begin(); pSize != m_sizes[s].end(); pSize++)
		{
			sort(pSize->OtherSizes.begin(), pSize->OtherSizes.end());
			// установка указателя на минимальный размер
			pSize->OtherSizes.SetMin();
		}
	}
}

void Raskroy::Begin(Parts &parts, const Parts &sheets)
{
	m_parts = parts;
	m_sheets = sheets;
}

float Raskroy::GetPercentCompleted()
{
	float total = (float)(m_sheets.size() * (m_sizes[0].size() + m_sizes[1].size()));
	if(total == 0.0f)
	{
		return 100.0f;
	}
	else
	{
		return (float)m_perebor2d.CompletedCounter / total * 100.0f;
	}
}

bool Raskroy::NextResult(t_result& out)
{
	// проверить остались ли детали
	/*Amounts::const_iterator pRemain = m_remains.begin();
	for (; pRemain != m_remains.end(); pRemain++)
		if (*pRemain > 0)
			break;
	if (pRemain == m_remains.end())
		return false; // детали кончились*/
	if(m_parts.size() == 0)
	{
		return false;
	}

	t_result bestResult;
	Amounts bestRashod(m_remains.size());
	bool first = true;
	m_perebor2d.ResetCompletedCounter();
	for (Parts::iterator pSheet = m_sheets.begin(); pSheet != m_sheets.end(); pSheet++)
	{
		Stat stat;
		stat.MakeZero();
		t_raskroy raskroy;

		BalanceWorkingSet(pSheet->Rect);

		Amounts rashod(m_remains.size());

		if (!m_perebor2d.Optimize(pSheet->Rect, stat, 0, raskroy, rashod))
			continue;
		if (bestResult.Statistics < stat || first) {
			bestResult.amount = m_remains / rashod;
			if (ControlRemains && bestResult.amount > pSheet->Amount)
				continue; // недостаточно листов

			bestResult.Statistics = stat;
			bestResult.raskroy = raskroy;
			bestResult.sheet = pSheet;
			bestRashod = rashod;
			first = false;
		}
	}
	if (first)
		throw CannotSetPartsException(&m_sheets, m_sizes, &m_remains);

	//m_remains -= bestRashod * bestResult.amount;
	//RemoveExostedSizes();
	SubstractPartsAmounts(bestRashod * bestResult.amount);
	if (ControlRemains)
		bestResult.sheet->Amount -= bestResult.amount;
#ifdef _DEBUG
	CheckResult(bestResult);
#endif
	out = bestResult;
	return true;
}

void Raskroy::CheckResult(const t_result& result)
{
	Stat stat;
	result.raskroy.CheckAndCalcStat(this->get_SawThickness(), result.sheet->Rect, &stat);
	assert(result.Statistics.IsEqual(stat, 1000000.0));
}

} // namespace Denisenko
} // namespace Raskroy