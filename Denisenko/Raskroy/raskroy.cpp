#include "stdafx.h"
#include "raskroy.h"

namespace Denisenko {
namespace Raskroy {

void Raskroy::remove_exosted_sizes(void)
{
	for (unsigned s = 0; s <= 1; s++)
	{
		t_sizes::iterator sizei = sizes[s].begin();
		while (sizei != sizes[s].end())
		{
			t_other_sizes::iterator osi = sizei->other_sizes.begin();
			while (osi != sizei->other_sizes.end())
			{
				if (remains[osi->offset] == 0)
				{
					sizei->other_sizes.erase(osi);
					osi = sizei->other_sizes.begin();
				}
				else
					osi++;
			}
			if (sizei->other_sizes.empty())
			{
				sizes[s].erase(sizei);
				sizei = sizes[s].begin();
			}
			else
				sizei++;
		}
	}
}

bool Raskroy::make_one_raskroy_result(/*[out]*/ t_result& res)
{
	// проверить остались ли детали
	for (t_amounts::const_iterator i = remains.begin(); i != remains.end(); i++)
		if (*i > 0)
			goto contine_raskroy;

	// детали кончились
	return false;

contine_raskroy:
	t_result best_result;
	t_amounts best_rashod;
	bool first = true;
	for (t_parts::iterator si = sheets.begin(); si != sheets.end(); si++)
	{
		t_stat stat(0);
		t_raskroy raskroy;
		t_amounts rashod;
		if (!perebor_2d.bylen_bywid(si->rect, stat, 0, raskroy, rashod) && !first && !(/*pcriteria->quality(*/stat/*)*/ > /*pcriteria->quality(*/best_result.stat/*)*/))
			continue;

		best_result.amount = remains/rashod;
		if (control_sheet_remains)
			if (best_result.amount > si->amount)	// недостаточно листов
				continue;

		best_result.stat = stat;
		best_result.raskroy = raskroy;
		best_result.sheet = si;
		best_rashod = rashod;
		first = false;
	}
	if (first)
		throw err_cannot_set_parts(sheets, sizes, remains);

	remains -= best_rashod*best_result.amount;
	remove_exosted_sizes();
	common_stat += best_result.stat;
	if (control_sheet_remains)
		best_result.sheet->amount -= best_result.amount;
	res = best_result;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy