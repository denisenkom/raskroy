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
				m_sizes[s].erase(pSize);
				pSize = m_sizes[s].begin();
			}
			else
				pSize++;
		}
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
	Amounts bestRashod;
	bool first = true;
	for (Parts::iterator pSheet = m_sheets.begin(); pSheet != m_sheets.end(); pSheet++)
	{
		Stat stat(0);
		t_raskroy raskroy;
		Amounts rashod;
		if (!m_perebor2d.Optimize(pSheet->Rect, stat, 0, raskroy, rashod))
			continue;
		if (bestResult.stat < stat || first) {
			bestResult.amount = m_remains / rashod;
			if (ControlRemains && bestResult.amount > pSheet->Amount)
				continue; // недостаточно листов

			bestResult.stat = stat;
			bestResult.raskroy = raskroy;
			bestResult.sheet = pSheet;
			bestRashod = rashod;
			first = false;
		}
	}
	if (first)
		throw err_cannot_set_parts(m_sheets, m_sizes, m_remains);

	m_remains -= bestRashod * bestResult.amount;
	RemoveExostedSizes();
	if (ControlRemains)
		bestResult.sheet->Amount -= bestResult.amount;
	out = bestResult;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy