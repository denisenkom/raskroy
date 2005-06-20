#include "stdafx.h"
#include "errors.h"
#include "Raskroy.h"

namespace Denisenko {
namespace Raskroy {

void Raskroy::RemoveExostedSizes(void)
{
	for (unsigned s = 0; s <= 1; s++)
	{
		for (Sizes::iterator size = m_sizes[s].begin(); size != m_sizes[s].end(); )
		{
			OtherSizes::iterator otherSize = size->OtherSizes.begin();
			while (otherSize != size->OtherSizes.end())
			{
				if (m_remains[otherSize->Offset] == 0)
				{
					size->OtherSizes.erase(otherSize);
					otherSize = size->OtherSizes.begin();
				}
				else
					otherSize++;
			}
			if (size->OtherSizes.empty())
			{
				m_sizes[s].erase(size);
				size = m_sizes[s].begin();
			}
			else
				size++;
		}
	}
}

bool Raskroy::NextResult(t_result& out)
{
	// проверить остались ли детали
	for (Amounts::const_iterator i = m_remains.begin(); i != m_remains.end(); i++)
		if (*i > 0)
			break;
	if (i == m_remains.end())
		return false; // детали кончились

	t_result bestResult;
	Amounts bestRashod;
	bool first = true;
	for (Parts::iterator si = m_sheets.begin(); si != m_sheets.end(); si++)
	{
		Stat stat(0);
		t_raskroy raskroy;
		Amounts rashod;
		if (!m_perebor2d.Optimize(si->Rect, stat, 0, raskroy, rashod)
			&& !first
			&& !(/*pcriteria->quality(*/bestResult.stat/*)*/ < /*pcriteria->quality(*/stat/*)*/))
			continue;

		bestResult.amount = m_remains / rashod;
		if (ControlRemains)
			if (bestResult.amount > si->Amount) // недостаточно листов
				continue;

		bestResult.stat = stat;
		bestResult.raskroy = raskroy;
		bestResult.sheet = si;
		bestRashod = rashod;
		first = false;
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