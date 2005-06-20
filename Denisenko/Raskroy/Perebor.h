#ifndef PereborH
#define PereborH

#include "common.h"

namespace Denisenko {
namespace Raskroy {

class Perebor {
	OtherSizes::const_iterator m_i;
	OtherSizes::const_iterator m_end;
	Amounts &m_remains;
	scalar m_remain;
	scalar m_sawThickness;
	scalar m_opilki;

	scalar Recursion(scalar size, Amounts &rashod);

public:

	scalar get_SawThickness() {return m_sawThickness;};
	void put_SawThickness(scalar newVal) {m_sawThickness = newVal;}
	scalar get_Remain() {return m_remain;}
	scalar get_Opilki() {return m_opilki;}

	Perebor(Amounts &remains, scalar sawThickness) : m_remains(remains), m_sawThickness(sawThickness) {}
	bool make(const Size &size, scalar otherSize, t_raskroy::t_details&, Amounts &rashod);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // PereborH