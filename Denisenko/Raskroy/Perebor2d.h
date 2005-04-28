#include "Perebor.h"

namespace Denisenko {
namespace Raskroy {

class Perebor2d {
	t_amounts &_remains;
	t_sizes *_sizes;
	scalar *_minSize;
	Perebor _perebor;

	bool Recursion(t_sizes::iterator begin, const t_rect&, t_stat&, int s, t_raskroy&, t_amounts &rashod);

public:

	Perebor2d(t_sizes sizes[], scalar minSize[], t_amounts &remains)
		: _sizes(sizes), _minSize(minSize), _remains(remains), _perebor(remains, 4) {}

	void SetCutWidth(double x) throw () {_perebor.saw_thickness = x;}

	double GetCutWidth(void) throw () {return _perebor.saw_thickness;}

	bool Optimize(const t_rect&, t_stat&, int s, t_raskroy&, t_amounts &rashod);
};

} // namespace Denisenko
} // namespace Raskroy