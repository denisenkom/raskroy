#include "Perebor.h"

namespace Denisenko {
namespace Raskroy {

class Perebor2d {
	t_amounts &m_remains;
	t_sizes *m_sizes;
	scalar *m_minSize;
	Perebor m_perebor;

	bool Recursion(t_sizes::iterator begin, const t_rect&, t_stat&, int s, t_raskroy&, t_amounts &rashod);

public:

	Perebor2d(t_sizes sizes[], scalar minSize[], t_amounts &remains)
		: m_sizes(sizes), m_minSize(minSize), m_remains(remains), m_perebor(remains, 4) {}

	void put_SawThickness(double x) throw () {m_perebor.put_SawThickness(x);}
	double get_SawThickness(void) throw () {return m_perebor.get_SawThickness();}
	bool Optimize(const t_rect&, t_stat&, int s, t_raskroy&, t_amounts &rashod);
};

} // namespace Denisenko
} // namespace Raskroy