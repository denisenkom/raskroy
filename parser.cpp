#include "types.hpp"
#include "parser.h"

namespace raskroy {

scalar parser::details(unsigned s, scalar pos[2], const t_rect &rect, const t_raskroy::t_details &details)
{
	scalar acc = 0;
	for (t_raskroy::t_details::const_iterator i = details.begin(); i != details.end(); i++)
		for (unsigned n = 0; n < i->num; n++)
		{
			t_parsed_part part;
			part.pos[s] = pos[s];
			part.pos[!s] = pos[!s] + acc;
			part.rect.size[s] = rect.size[s];
			part.rect.size[!s] = i->size;

			//part.part = 
			assert(poutresult);
			poutresult->parts.push_back(part);
			// нужно найти деталь
			acc += i->size;
			if (n < i->num-1)
			{
				t_parsed_cut cut;
				cut.pos[s] = pos[s];
				cut.pos[!s] = pos[!s] + acc + half_saw_thickness;
				cut.s = s;
				cut.length = rect.size[s];
				assert(poutresult);
				poutresult->cuts.push_back(cut);
				acc += saw_thickness;
			}
		}

	return acc;
}

void parser::recursive(scalar pos[2], const t_rect &rect, const t_raskroy &raskroy)
{
	t_parsed_cut cut;
	cut.s = !raskroy.s;
	cut.length = rect.size[!raskroy.s];
	cut.pos[!raskroy.s] = pos[!raskroy.s];
	cut.pos[raskroy.s] = pos[raskroy.s] + raskroy.cut*raskroy.kratnostj + half_saw_thickness;
	assert(poutresult);
	poutresult->cuts.push_back(cut);
	scalar remain=0;
	scalar pos1[2];
	//raskroy_api::scalar acc = 0;
	pos1[0] = pos[0];
	pos1[1] = pos[1];
	for (unsigned k = 0; k < raskroy.kratnostj; k++)
	{
		t_rect rect1(rect);
		rect1.size[raskroy.s] = raskroy.cut;
		remain = details(raskroy.s, pos1, rect1, raskroy.details);
		pos1[raskroy.s] += raskroy.cut + saw_thickness;

		if (k < raskroy.kratnostj-1)
		{
			cut.s = !raskroy.s;
			cut.length = remain;
			cut.pos[!raskroy.s] = pos1[!raskroy.s];
			cut.pos[raskroy.s] = pos1[raskroy.s] - half_saw_thickness;
			assert(poutresult);
			poutresult->cuts.push_back(cut);
		}
	}

	cut.pos[raskroy.s] = pos[raskroy.s];
	cut.pos[!raskroy.s] = pos[!raskroy.s] + remain + half_saw_thickness;
	cut.s = raskroy.s;
	cut.length = raskroy.cut*raskroy.kratnostj;
	assert(poutresult);
	poutresult->cuts.push_back(cut);

	if (raskroy.watchRemain())
	{
		t_rect rect1;
		rect1.size[raskroy.s] = raskroy.cut*raskroy.kratnostj;
		rect1.size[!raskroy.s] = rect.size[!raskroy.s]-remain;
		pos1[raskroy.s] = pos[raskroy.s];
		pos1[!raskroy.s] = pos[!raskroy.s] + remain;
		recursive(pos1, rect1, *raskroy.watchRemain());
	}

	if (raskroy.watchRecurse())
	{
		t_rect rect1(rect);
		rect1.size[raskroy.s] = rect.size[raskroy.s] - (raskroy.cut+saw_thickness)*raskroy.kratnostj;
		pos1[raskroy.s] = pos[raskroy.s] + (raskroy.cut+saw_thickness)*raskroy.kratnostj;
		pos1[!raskroy.s] = pos[!raskroy.s];
		recursive(pos1, rect1, *raskroy.watchRecurse());
	}
}

void parser::parse(const t_result& result1, t_parsed_result& result2, scalar saw_thickness)
{
	this->saw_thickness = saw_thickness;
	half_saw_thickness = saw_thickness/2;

	poutresult = &result2;
	assert(poutresult);
	poutresult->cuts.clear();
	assert(poutresult);
	poutresult->parts.clear();
	result2.amount = result1.amount;
	result2.stat = result1.stat;
	result2.sheet = *result1.sheet;
	scalar pos[2] = {0, 0};
	recursive(pos, result1.sheet->rect, result1.raskroy);
}

}