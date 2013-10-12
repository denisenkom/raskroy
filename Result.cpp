#include "stdafx.h"
#include "Result.h"

namespace Denisenko {
namespace Raskroy {

void t_raskroy::set(int s,
	unsigned kratnostj,
	scalar cut,
	t_details &details,
	t_raskroy *premain,
	t_raskroy *precurse)
{
	this->s = s;
	this->kratnostj = kratnostj;
	this->cut = cut;
	this->details = details;
	delete this->premain;
	this->premain = premain ? new t_raskroy(*premain) : 0;
	delete this->precurse;
	this->precurse = precurse ? new t_raskroy(*precurse) : 0;
}

t_raskroy& t_raskroy::operator = (const t_raskroy &orig)
{
	delete premain;
	delete precurse;

	s = orig.s;
	kratnostj = orig.kratnostj;
	cut = orig.cut;
	details = orig.details;
	premain = orig.premain;
	precurse = orig.precurse;

	orig.premain = 0;
	orig.precurse = 0;

	return *this;
}

void t_raskroy::attachRemain(t_raskroy &remain) {
	if (premain)
		*premain = remain;
	else
		premain = new t_raskroy(remain);
}

void t_raskroy::attachRecurse(t_raskroy &recurse) {
	if (precurse)
		*precurse = recurse;
	else
		precurse = new t_raskroy(recurse);
}

void t_raskroy::CheckAndCalcStat(scalar cutThickness, const Rect& rect, Stat* outStat) const
{
	Stat stat;
	stat.MakeZero();
	stat.Opilki += (double)rect.Size[!s] * (double)std::min(cutThickness, rect.Size[s] - (cut + cutThickness) * kratnostj + cutThickness);
	scalar detailsWithCutsLength = 0;
	unsigned cuts = 0;
	for(t_details::const_iterator i = details.begin(); i != details.end(); i++)
	{
		detailsWithCutsLength += (i->size + cutThickness) * i->num;
		cuts += i->num;
	}
	stat.Opilki += ((cut + cutThickness) * kratnostj - cutThickness) * std::min(cutThickness, rect.Size[!s] - detailsWithCutsLength + cutThickness);
	stat.Opilki += (detailsWithCutsLength - cutThickness) * cutThickness * (kratnostj - 1);
	stat.Opilki += cut * cutThickness * (cuts - 1) * kratnostj;

	Stat remainStat;
	Rect remainRect;
	remainRect.Size[s] = std::max<scalar>((cut + cutThickness) * kratnostj - cutThickness, 0);
	remainRect.Size[!s] = std::max<scalar>(rect.Size[!s] - detailsWithCutsLength, 0);
	if(premain != 0)
	{
		premain->CheckAndCalcStat(cutThickness, remainRect, &remainStat);
	}
	else
	{
		remainStat.MakeZero();
		remainStat.AddScrap(remainRect);
	}
	stat += remainStat;
	Stat recurseStat;
	Rect recurseRect;
	recurseRect.Size[s] = std::max<scalar>(rect.Size[s] - (cut + cutThickness) * kratnostj, 0);
	recurseRect.Size[!s] = rect.Size[!s];
	if(precurse != 0)
	{
		precurse->CheckAndCalcStat(cutThickness, recurseRect, &recurseStat);
	}
	else
	{
		recurseStat.MakeZero();
		recurseStat.AddScrap(recurseRect);
	}
	stat += recurseStat;
	*outStat = stat;
}

} // Raskroy
} // Denisenko
