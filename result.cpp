#include "stdafx.h"
#include "result.h"

namespace Denisenko {
namespace Raskroy {

void OldLayoutResult::set(int s,
	unsigned kratnostj,
	scalar cut,
	Details &details,
	OldLayoutResult *premain,
	OldLayoutResult *precurse)
{
	this->s = s;
	this->kratnostj = kratnostj;
	this->cut = cut;
	this->details = details;
	delete this->premain;
	this->premain = premain ? new OldLayoutResult(*premain) : 0;
	delete this->precurse;
	this->precurse = precurse ? new OldLayoutResult(*precurse) : 0;
}

OldLayoutResult& OldLayoutResult::operator = (const OldLayoutResult &orig)
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

void OldLayoutResult::attachRemain(OldLayoutResult &remain) {
	if (premain)
		*premain = remain;
	else
		premain = new OldLayoutResult(remain);
}

void OldLayoutResult::attachRecurse(OldLayoutResult &recurse) {
	if (precurse)
		*precurse = recurse;
	else
		precurse = new OldLayoutResult(recurse);
}

void OldLayoutResult::CheckAndCalcStat(scalar cutThickness, const Rect& rect, Stat* outStat) const
{
	Stat stat;
	stat.MakeZero();
	stat.Opilki += (double)rect.Size[!s] * (double)std::min(cutThickness, rect.Size[s] - (cut + cutThickness) * kratnostj + cutThickness);
	scalar detailsWithCutsLength = 0;
	unsigned cuts = 0;
	for(Details::const_iterator i = details.begin(); i != details.end(); i++)
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


void LayoutElementBuilder::_convert(LayoutElement & out) const {
    out.type = type;
    out.size = size;
    if (type == ELEM_SUBLAYOUT) {
        std::unique_ptr<Layout> out_sublayout(new Layout);
        layout->to_layout(*out_sublayout);
        out.layout = out_sublayout.release();
    } else if (type == ELEM_RECT) {
        bool found = false;
        for (auto i = part->parts.begin(); i != part->parts.end(); i++) {
            if ((*i)->Amount > 0) {
                (*i)->Amount -= 1;
                out.rect_index = (*i)->Tag;
                found = true;
                break;
            }
        }
        assert(found);
    }
}


void LayoutBuilder::begin_appending() {
    assert(elements.size() == 0);  // should be called before appending
    remain = rect.Size[axis];
}


void LayoutBuilder::append_part(Part * part, scalar size) {
    assert(size <= remain);
    LayoutElementBuilder part_el;
    part_el.type = ELEM_RECT;
    part_el.size = size;
    // TODO: implement the case when there are many parts
    // on the other_size
    part_el.rect = rect;
    part_el.rect.Size[axis] = size;
    part_el.part = part;
    elements.push_back(part_el);
    remain -= size;
}


void LayoutBuilder::simplify() {
    // collapse trivial sublayouts
    bool simplify_more = true;
    while (simplify_more) {
        simplify_more = false;
        if (elements.size() == 1) {
            if (elements.back().type == ELEM_SUBLAYOUT) {
                auto sublayout = elements.back().layout;
                axis = sublayout->axis;
                elements.swap(sublayout->elements);
                sublayout->elements.clear();
                delete sublayout;
                simplify_more = true;
            }
            else {

            }
        }
        else {
            for (auto i = elements.begin(); i != elements.end(); i++)
            {
                simplify_more = false;
                if (i->type == ELEM_SUBLAYOUT && i->layout->axis == axis) {
                    // merge sublayouts with the same direction as current layout
                    auto sublayout = i->layout;
                    elements.splice(i, sublayout->elements);
                    elements.erase(i);
                    delete sublayout;
                    simplify_more = true;
                    break;
                }
                else if (i->type == ELEM_SUBLAYOUT && i->layout->elements.size() == 1) {
                    // collapse unnecessary sub-layouts
                    auto el = &*i->layout->elements.begin();
                    i->type = el->type;
                    i->size = el->rect.Size[axis];
                    i->rect = el->rect;
                    i->part = el->part;
                    auto del_layout = i->layout;
                    i->layout = el->layout;
                    el->layout = nullptr;
                    delete del_layout;
                    simplify_more = true;
                    break;
                }
            }
        }
    }

    // simplify all sub-layouts recursively
    for (auto i = elements.begin(); i != elements.end(); i++)
    {
        if (i->type == ELEM_SUBLAYOUT)
            i->layout->simplify();
    }
}


void LayoutBuilder::check() const {
    scalar size = 0;
    for (auto i = elements.begin(); i != elements.end(); i++) {
        size += i->size;
        if (i->type == ELEM_SUBLAYOUT) {
            auto subrect = rect;
            subrect.Size[axis] = i->size;
            assert(subrect == i->layout->rect);
            i->layout->check();
        }
    }
    assert(size == rect.Size[axis]);
}

} // Raskroy
} // Denisenko
