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


void LayoutElementBuilder::_convert(LayoutElement & out) {
    out.type = type;
    out.size = size;
    if (type == ELEM_SUBLAYOUT) {
        std::auto_ptr<Layout> out_sublayout(new Layout);
        layout->to_layout(*out_sublayout);
        out.layout = out_sublayout.release();
    } else if (type == ELEM_RECT) {
        out.rect_index = rect_index;
    }
}


void LayoutBuilder::simplify() {
    // collapse trivial sublayouts
    bool simplify_more = true;
    while (simplify_more) {
        simplify_more = false;
        if (elements.size() == 1 && elements.back().type == ELEM_SUBLAYOUT) {
            LayoutBuilder * sublayout = elements.back().layout;
            axis = sublayout->axis;
            elements.swap(sublayout->elements);
            sublayout->elements.clear();
            delete sublayout;
            simplify_more = true;
        }
    }

    // simplify all sub-layouts recursively
    for (std::list<LayoutElementBuilder>::iterator i = elements.begin();
         i != elements.end(); i++)
    {
        if (i->type == ELEM_SUBLAYOUT)
            i->layout->simplify();
    }

    // merge sublayouts with the same direction as current layout
    simplify_more = true;
    while (simplify_more) {
        for (std::list<LayoutElementBuilder>::iterator i = elements.begin();
             i != elements.end(); i++)
        {
            simplify_more = false;
            if (i->type == ELEM_SUBLAYOUT && i->layout->axis == axis) {
                LayoutBuilder * sublayout = i->layout;
                elements.splice(i, sublayout->elements);
                elements.erase(i);
                delete sublayout;
                simplify_more = true;
                break;
            }
        }
    }
}

} // Raskroy
} // Denisenko
