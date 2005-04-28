#include "stdafx.h"
#include "raskroy.h"

namespace Denisenko {
namespace Raskroy {

void Raskroy::RemoveExostedSizes(void)
{
	for (unsigned s = 0; s <= 1; s++)
	{
		for (t_sizes::iterator si = _sizes[s].begin(); si != _sizes[s].end(); )
		{
			t_other_sizes::iterator osi = si->other_sizes.begin();
			while (osi != si->other_sizes.end())
			{
				if (_remains[osi->offset] == 0)
				{
					si->other_sizes.erase(osi);
					osi = si->other_sizes.begin();
				}
				else
					osi++;
			}
			if (si->other_sizes.empty())
			{
				_sizes[s].erase(si);
				si = _sizes[s].begin();
			}
			else
				si++;
		}
	}
}

bool Raskroy::MakeOneResult(t_result& out)
{
	// проверить остались ли детали
	for (t_amounts::const_iterator i = _remains.begin(); i != _remains.end(); i++)
		if (*i > 0)
			break;
	if (i == _remains.end())
		return false; // детали кончились

	t_result bestResult;
	t_amounts bestRashod;
	bool first = true;
	for (t_parts::iterator si = _sheets.begin(); si != _sheets.end(); si++)
	{
		t_stat stat(0);
		t_raskroy raskroy;
		t_amounts rashod;
		if (!_perebor2d.bylen_bywid(si->rect, stat, 0, raskroy, rashod)
			&& !first
			&& !(/*pcriteria->quality(*/stat/*)*/ > /*pcriteria->quality(*/bestResult.stat/*)*/))
			continue;

		bestResult.amount = _remains / rashod;
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
		throw err_cannot_set_parts(_sheets, _sizes, _remains);

	_remains -= bestRashod * bestResult.amount;
	RemoveExostedSizes();
	if (ControlRemains)
		bestResult.sheet->amount -= bestResult.amount;
	out = bestResult;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy