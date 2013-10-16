#include "stdafx.h"
#include "errors.h"
#include "Raskroy.h"

namespace Denisenko {
namespace Raskroy {

void Raskroy::RemoveExostedSizes(void)
{
	for (unsigned s = 0; s <= 1; s++)
	{
		Sizes::iterator pSize = m_sizes[s].begin();
		while (pSize != m_sizes[s].end())
		{
			OtherSizes::iterator pOtherSize = pSize->other_sizes.begin();
			while (pOtherSize != pSize->other_sizes.end())
			{
				if (m_remains[pOtherSize->Offset] == 0)
				{
					pSize->other_sizes.erase(pOtherSize);
					pOtherSize = pSize->other_sizes.begin();
				}
				else
					pOtherSize++;
			}
			if (pSize->other_sizes.empty())
			{
				m_sizes[s].erase(pSize);
				pSize = m_sizes[s].begin();
			}
			else
			{
				pSize->other_sizes.SetMin();
				pSize++;
			}
		}
	}
}

void Raskroy::Begin(Parts &parts, const Parts &sheets)
{
	m_remains.clear();
	for (int s = 0; s <= 1; s++)
	{
		m_sizes[s].clear();
		for (Parts::iterator pPart = parts.begin(); pPart != parts.end(); pPart++)
			m_sizes[s].AddPart(*pPart, s, m_remains);

        // order from big to small
        std::sort(m_sizes[s].begin(), m_sizes[s].end(), std::greater_equal<Size>());
		for (Sizes::iterator pSize = m_sizes[s].begin(); pSize != m_sizes[s].end(); pSize++)
		{
            std::sort(pSize->other_sizes.begin(), pSize->other_sizes.end(),
                      std::greater_equal<OtherSize>());
			// установка указателя на минимальный размер
			pSize->other_sizes.SetMin();
		}
	}
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
		return (float)m_perebor2d.GetCompletedCounter() / total * 100.0f;
	}
}

bool Raskroy::NextResult(t_result& out)
{
	// проверить остались ли детали
	Amounts::const_iterator pRemain = m_remains.begin();
	for (; pRemain != m_remains.end(); pRemain++)
		if (*pRemain > 0)
			break;
	if (pRemain == m_remains.end())
		return false; // детали кончились

	t_result bestResult;
	Amounts bestRashod(m_remains.size());
	bool first = true;
	m_perebor2d.ResetCompletedCounter();
	for (Parts::iterator pSheet = m_sheets.begin(); pSheet != m_sheets.end(); pSheet++)
	{
		Stat stat;
		stat.MakeZero();
		t_raskroy raskroy;
		Amounts rashod(m_remains.size());
		if (!m_perebor2d.Optimize(pSheet->rect, stat, 0, raskroy, rashod))
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

	m_remains -= bestRashod * bestResult.amount;
	RemoveExostedSizes();
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
	result.raskroy.CheckAndCalcStat(this->get_SawThickness(), result.sheet->rect, &stat);
	assert(result.Statistics.IsEqual(stat, 1000000.0));
}

} // namespace Denisenko
} // namespace Raskroy
