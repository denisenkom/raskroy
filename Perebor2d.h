#ifndef Perebor2dH
#define Perebor2dH

#include "Perebor.h"

namespace Denisenko {
namespace Raskroy {

const scalar DEFAULT_SAW_THICKNESS = 4;

class Perebor2d {
	Amounts *m_remains;
	Sizes *m_sizes;
	scalar *m_minSize;
	Perebor m_perebor;
	int m_nesting;
	int m_completedCounter;

	bool Recursion(Sizes::iterator begin, const Rect&, Stat&, int s, t_raskroy&, Amounts &rashod);

public:

	Perebor2d(Sizes sizes[], scalar minSize[], Amounts *remains)
		: m_sizes(sizes), m_minSize(minSize), m_remains(remains),
		m_perebor(remains, DEFAULT_SAW_THICKNESS), m_nesting(0), m_completedCounter(0)
	{
	}

	void put_SawThickness(scalar x) throw () {m_perebor.put_SawThickness(x);}
	scalar get_SawThickness(void) throw () {return m_perebor.get_SawThickness();}
	bool Optimize(const Rect&, Stat&, int s, t_raskroy&, Amounts &rashod);
    bool new_optimize(const Rect &rect, LayoutBuilder &layout, Amounts &consume);
	void ResetCompletedCounter() { m_completedCounter = 0; }
	int GetCompletedCounter() { return m_completedCounter; }
};

} // namespace Denisenko
} // namespace Raskroy

#endif // Perebor2dH
