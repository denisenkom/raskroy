#ifndef PereborH
#define PereborH

#include "common.h"

namespace Denisenko {
namespace Raskroy {

class Perebor {
	t_other_sizes::const_iterator m_i;
	t_other_sizes::const_iterator m_end;
	t_amounts &m_remains;
	scalar m_remain;
	scalar m_sawThickness;
	scalar m_opilki;

	scalar Recursion(scalar size, t_amounts &rashod);

public:

	scalar get_SawThickness() {return m_sawThickness;};
	void put_SawThickness(scalar newVal) {m_sawThickness = newVal;}
	scalar get_Remain() {return m_remain;}
	scalar get_Opilki() {return m_opilki;}

	Perebor(t_amounts &remains, scalar sawThickness) : m_remains(remains), m_sawThickness(sawThickness) {}
	bool make(const Size &size, scalar otherSize, t_raskroy::t_details&, t_amounts &rashod);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // PereborH