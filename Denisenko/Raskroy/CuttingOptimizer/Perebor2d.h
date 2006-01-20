#ifndef Perebor2dH
#define Perebor2dH

#include "Perebor.h"

namespace Denisenko {
namespace Raskroy {

const float DEFAULT_SAW_THICKNESS = 4.0;

class Perebor2d {
	Amounts &m_remains;
	Sizes *m_sizes;
	scalar *m_minSize;
	Perebor m_perebor;

	bool Recursion(Sizes::iterator begin, const Rect&, Stat&, int s, t_raskroy&, Amounts &rashod);

public:

	Perebor2d(Sizes sizes[], scalar minSize[], Amounts &remains)
		: m_sizes(sizes), m_minSize(minSize), m_remains(remains), m_perebor(remains, DEFAULT_SAW_THICKNESS) {}

	void put_SawThickness(double x) throw () {m_perebor.put_SawThickness(x);}
	double get_SawThickness(void) throw () {return m_perebor.get_SawThickness();}
	bool Optimize(const Rect&, Stat&, int s, t_raskroy&, Amounts &rashod);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // Perebor2dH