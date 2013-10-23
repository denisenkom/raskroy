#ifndef Layout1dH
#define Layout1dH

#include "result.h"

namespace Denisenko {
namespace Raskroy {

class Layout1d {
	OtherSizes::const_iterator m_pOtherSize;
	OtherSizes::const_iterator m_pEndOtherSize;
	Amounts *m_remains;
	scalar m_sawThickness;

    scalar Recursion(scalar size, std::list<std::pair<const OtherSize *, unsigned> > & layout);

public:
	scalar get_SawThickness() throw() {return m_sawThickness;};
	void   put_SawThickness(scalar newVal) throw() {m_sawThickness = newVal;}

	Layout1d(Amounts *remains, scalar sawThickness) : m_remains(remains), m_sawThickness(sawThickness) {}
	bool Make(const Size &size, scalar otherSize, OldLayoutResult::t_details& o_details, Amounts &o_rashods, scalar &o_remain, double &o_opilki);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // Layout1dH
