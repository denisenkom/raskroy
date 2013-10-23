#include "stdafx.h"
#include "layout1d.h"

namespace Denisenko {
namespace Raskroy {

// 1D layout recursion
// Parameters:
//	[i] size - maximum size where to fit segments
//	[o] rashod - consumption of segments
// this:
//	[io] m_pOtherSize
//	[i]  m_pEndOtherSize
//	[i]  m_remains
scalar Layout1d::Recursion(scalar i_size, std::list<std::pair<const OtherSize*, unsigned> > & layout)
{
    unsigned amount = 0;
    std::for_each(m_pOtherSize->parts.begin(), m_pOtherSize->parts.end(),
                  [&amount, this](Part * part){amount += (*m_remains)[part->AmountOffset];});
	if (m_pOtherSize != m_pEndOtherSize)
	{
		scalar bestRemain = i_size;
		bool first = true;
		scalar size = i_size;
		unsigned n = 0;

		while (n <= amount && size > m_sawThickness)
		{
			scalar remain;
            std::list<std::pair<const OtherSize *, unsigned> > sublayout;
			m_pOtherSize++;
			remain = Recursion(size, sublayout);
			m_pOtherSize--;
			if (remain < bestRemain || first)
			{
				bestRemain = remain;
                sublayout.push_front(std::make_pair(&*m_pOtherSize, n));
                layout.swap(sublayout);
				if (bestRemain <= 0) // this is the best possible
					return bestRemain;
				first = false;
			}
			size -= m_pOtherSize->Value + m_sawThickness;
			n++;
            // here size can be < 0 which is ok if remain is smaller than
            // the saw size
		}
        // if nothing layed out return zeros
		//if (best == size)
		//{
		//	rashod.resize(remains.size());
		//	std::fill(rashod.begin(), rashod.end(), 0);
		//}
		return bestRemain;
	}
	else
	{
		scalar fullSize = m_pOtherSize->Value + m_sawThickness;
		unsigned n = unsigned((i_size + m_sawThickness) / fullSize);
		if (n > amount)
			n = amount;
        layout.clear();
        layout.push_back(std::make_pair(&*m_pOtherSize, n));
		//o_rashods.resize(m_remains->size());
        // here size can be < 0 which is ok if remain is smaller than
        // the saw size
		return i_size - n * fullSize;
	}
}

// 1D layout
// Parameters:
//		[i] size - list of segments is in size.other_sizes
//		[i] other_size - target size
//		[o] stat - statistics
//		[o] details - layout result, empty container should be passed on input
//		[o] rashod - consumption of segments
// ¬озвращает true если хот€ бы одна деталь установлена
bool Layout1d::Make(const Size &size, scalar otherSize, t_raskroy::t_details &o_details, Amounts &o_rashods, scalar &o_remain, double &o_opilki)
{
	if (otherSize < size.other_sizes.Min->Value)
		return false;

	// setting up variables for recursion
	m_pOtherSize = size.other_sizes.begin();
	m_pEndOtherSize = size.other_sizes.end();
	m_pEndOtherSize--;
	// recursively try sizes [i..end]
    std::list<std::pair<const OtherSize *, unsigned> > layout;
	scalar remain = Recursion(otherSize, layout);
	if (remain == otherSize)	// if nothing was layed out
		return false;

	auto cuts = 0;  // number of cuts
	for (auto sz = layout.begin(); sz != layout.end(); sz++)
	{
        auto consumed = sz->second;
        auto os = sz->first;
        if (consumed > 0)
		{
            auto consume_remain = consumed;
			t_raskroy::t_detail detail;
            // fill o_rashods
            // and fill parts attribute
            for (auto part_iter = os->parts.begin();
                 part_iter != os->parts.end(); part_iter++)
            {
                auto ppart = *part_iter;
                auto part_remain = (*m_remains)[ppart->AmountOffset];
                auto to_consume = std::min(part_remain, consume_remain);
                o_rashods[ppart->AmountOffset] += to_consume;
                consume_remain -= to_consume;
                detail.parts.push_back(std::make_pair(ppart, to_consume));
            }
            detail.size = sz->first->Value;
            detail.num = consumed;
			o_details.push_back(detail);
            cuts += consumed;  // number of cuts
		}
	}
	// Calculating sawdust
	double opilki = (double)size.Value * (double)m_sawThickness * (double)cuts;
	// If last cut is't full than reduce sawdust
	if (remain < 0)
	{
		opilki += (double)size.Value * (double)remain;
		remain = 0;
	}
	o_opilki = opilki;
	o_remain = remain;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy
