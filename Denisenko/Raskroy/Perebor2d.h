#include "Perebor.h"

namespace Denisenko {
namespace Raskroy {

class Perebor2d {
	t_amounts &remains;
	t_sizes *sizes;
	scalar *minimum_size;
	unsigned recursion_depth;
	Perebor Perebor;
	monitor default_monitor;
	monitor *pmonitor;

	bool recursive(t_sizes::iterator begin, const t_rect&, t_stat&, int s, t_raskroy&, t_amounts &rashod);

public:
	unsigned max_recursion_depth;

	Perebor2d(t_sizes sizes[], scalar min_size[], t_amounts &remains/*, criteria &criteria*/)
		: recursion_depth(0), max_recursion_depth(8), /*pcriteria(&criteria),*/
		pmonitor(&default_monitor), sizes(sizes), minimum_size(min_size),
		remains(remains), Perebor(remains, 4) {}
	void set_monitor(monitor &x) throw () {pmonitor = &x;}
	void set_cut_width(double x) throw () {Perebor.saw_thickness = x;}
	double get_cut_width(void) throw () {return Perebor.saw_thickness;}

	bool bylen_bywid(const t_rect&, t_stat&, int s, t_raskroy&, t_amounts &rashod);
};

} // namespace Denisenko
} // namespace Raskroy