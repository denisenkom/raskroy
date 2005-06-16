#include "stdafx.h"
#include "types.h"
#include "Parser.h"

namespace Denisenko {
namespace Raskroy {

scalar Parser::Details(unsigned s, scalar pos[2], const t_rect &rect, const t_raskroy::t_details &details)
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

			details_summary_square += rect.size[s] * i->size;

			//part.part = 
			assert(m_pOutResult);
			m_pOutResult->parts.push_back(part);
			// нужно найти деталь
			acc += i->size;
			if (n < i->num-1)
			{
				t_parsed_cut cut;
				cut.pos[s] = pos[s];
				cut.pos[!s] = pos[!s] + acc + m_halfSawThickness;
				cut.s = s;
				cut.length = rect.size[s];
				assert(m_pOutResult);
				m_pOutResult->cuts.push_back(cut);
				acc += m_sawThickness;
			}
		}

	return acc;
}

void Parser::Recursion(scalar pos[2], const t_rect &rect, const t_raskroy &raskroy)
{
	t_parsed_cut cut;
	cut.s = !raskroy.s;
	cut.length = rect.size[!raskroy.s];
	cut.pos[!raskroy.s] = pos[!raskroy.s];
	cut.pos[raskroy.s] = pos[raskroy.s] + raskroy.cut * raskroy.kratnostj + m_halfSawThickness;
	assert(m_pOutResult);
	m_pOutResult->cuts.push_back(cut);
	scalar remain=0;
	scalar pos1[2];
	//raskroy_api::scalar acc = 0;
	pos1[0] = pos[0];
	pos1[1] = pos[1];
	for (unsigned k = 0; k < raskroy.kratnostj; k++)
	{
		t_rect rect1(rect);
		rect1.size[raskroy.s] = raskroy.cut;
		remain = Details(raskroy.s, pos1, rect1, raskroy.details);
		pos1[raskroy.s] += raskroy.cut + m_sawThickness;
		if (k < raskroy.kratnostj-1)
		{
			cut.s = !raskroy.s;
			cut.length = remain;
			cut.pos[!raskroy.s] = pos1[!raskroy.s];
			cut.pos[raskroy.s] = pos1[raskroy.s] - m_halfSawThickness;
			assert(m_pOutResult);
			m_pOutResult->cuts.push_back(cut);
		}
	}

	cut.pos[raskroy.s] = pos[raskroy.s];
	cut.pos[!raskroy.s] = pos[!raskroy.s] + remain + m_halfSawThickness;
	cut.s = raskroy.s;
	cut.length = raskroy.cut * raskroy.kratnostj;
	assert(m_pOutResult);
	m_pOutResult->cuts.push_back(cut);

	if (raskroy.watchRemain())
	{
		t_rect rect1;
		rect1.size[raskroy.s] = raskroy.cut * raskroy.kratnostj;
		rect1.size[!raskroy.s] = rect.size[!raskroy.s] - remain;
		pos1[raskroy.s] = pos[raskroy.s];
		pos1[!raskroy.s] = pos[!raskroy.s] + remain;
		Recursion(pos1, rect1, *raskroy.watchRemain());
	}

	if (raskroy.watchRecurse())
	{
		t_rect rect1(rect);
		rect1.size[raskroy.s] = rect.size[raskroy.s] - (raskroy.cut + m_sawThickness) * raskroy.kratnostj;
		pos1[raskroy.s] = pos[raskroy.s] + (raskroy.cut + m_sawThickness) * raskroy.kratnostj;
		pos1[!raskroy.s] = pos[!raskroy.s];
		Recursion(pos1, rect1, *raskroy.watchRecurse());
	}
}

void Parser::Parse(const t_result& result1, t_parsed_result& result2, scalar sawThickness)
{
	m_sawThickness = sawThickness;
	m_halfSawThickness = sawThickness / 2;

	details_summary_square = 0;
	m_pOutResult = &result2;
	assert(m_pOutResult);
	m_pOutResult->cuts.clear();
	assert(m_pOutResult);
	m_pOutResult->parts.clear();
	result2.amount = result1.amount;
	result2.stat = result1.stat;
	result2.sheet = *result1.sheet;
	scalar pos[2] = {0, 0};
	Recursion(pos, result1.sheet->rect, result1.raskroy);
}

} // namespace Denisenko
} // namespace Raskroy