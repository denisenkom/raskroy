#include "stdafx.h"
#include "raskroy.h"

namespace Denisenko {
namespace Raskroy {

void Raskroy::RemoveExostedSizes(void)
{
	for (unsigned s = 0; s <= 1; s++)
	{
		for (t_sizes::iterator si = m_sizes[s].begin(); si != m_sizes[s].end(); )
		{
			t_other_sizes::iterator osi = si->other_sizes.begin();
			while (osi != si->other_sizes.end())
			{
				if (m_remains[osi->offset] == 0)
				{
					si->other_sizes.erase(osi);
					osi = si->other_sizes.begin();
				}
				else
					osi++;
			}
			if (si->other_sizes.empty())
			{
				m_sizes[s].erase(si);
				si = m_sizes[s].begin();
			}
			else
				si++;
		}
	}
}

bool Raskroy::NextResult(t_result& out)
{
	// проверить остались ли детали
	for (t_amounts::const_iterator i = m_remains.begin(); i != m_remains.end(); i++)
		if (*i > 0)
			break;
	if (i == m_remains.end())
		return false; // детали кончились

	t_result bestResult;
	t_amounts bestRashod;
	bool first = true;
	for (t_parts::iterator si = m_sheets.begin(); si != m_sheets.end(); si++)
	{
		t_stat stat(0);
		t_raskroy raskroy;
		t_amounts rashod;
		if (!m_perebor2d.Optimize(si->rect, stat, 0, raskroy, rashod)
			&& !first
			&& !(/*pcriteria->quality(*/stat/*)*/ > /*pcriteria->quality(*/bestResult.stat/*)*/))
			continue;

		bestResult.amount = m_remains / rashod;
		if (ControlRemains)
			if (bestResult.amount > si->amount) // недостаточно листов
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
		bestResult.sheet->amount -= bestResult.amount;
	out = bestResult;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy