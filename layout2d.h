#ifndef Layout2dH
#define Layout2dH

#include "layout1d.h"

namespace Denisenko {
namespace Raskroy {

const scalar DEFAULT_SAW_THICKNESS = 4;

class Layout2d {
	Amounts *m_remains;
	Sizes *m_sizes;
	scalar *m_minSize;
	Layout1d m_layout1d;
	int m_nesting;
	int m_completedCounter;

	bool Recursion(Sizes::iterator begin, const Rect&, Stat&, int s, OldLayoutResult&, Amounts &rashod);

public:

	Layout2d(Sizes sizes[], scalar minSize[], Amounts *remains)
		: m_sizes(sizes), m_minSize(minSize), m_remains(remains),
		m_layout1d(remains, DEFAULT_SAW_THICKNESS), m_nesting(0), m_completedCounter(0)
	{
	}

	void put_SawThickness(scalar x) throw () {m_layout1d.put_SawThickness(x);}
	scalar get_SawThickness(void) throw () {return m_layout1d.get_SawThickness();}
	bool Optimize(const Rect&, Stat&, int s, OldLayoutResult&, Amounts &rashod);
    bool new_optimize(const Rect &rect, LayoutBuilder &layout);
	void ResetCompletedCounter() { m_completedCounter = 0; }
	int GetCompletedCounter() { return m_completedCounter; }
};

} // namespace Denisenko
} // namespace Raskroy

#endif // Layout2dH
