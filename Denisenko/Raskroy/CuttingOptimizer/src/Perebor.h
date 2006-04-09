#ifndef PereborH
#define PereborH

#include "common.h"
#include "Result.h"

namespace Denisenko {
namespace Raskroy {

class Perebor {
	OtherSizes::const_iterator m_pOtherSize;
	OtherSizes::const_iterator m_pEndOtherSize;
	Amounts *m_remains;
	scalar m_sawThickness;

	scalar Recursion(scalar size, Amounts &rashods);

public:
	scalar get_SawThickness() throw() {return m_sawThickness;};
	void   put_SawThickness(scalar newVal) throw() {m_sawThickness = newVal;}

	Perebor(Amounts *remains, scalar sawThickness) : m_remains(remains), m_sawThickness(sawThickness) {}
	bool Make(const Size &size, scalar otherSize, t_raskroy::t_details& o_details, Amounts &o_rashods, scalar &o_remain, double &o_opilki);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // PereborH