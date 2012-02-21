#ifndef PEREBOR_2D_H
#define PEREBOR_2D_H

#include "perebor.h"

namespace raskroy {

	class Perebor2D {
		t_factory factory;
		t_amounts &remains;
		t_sizes *sizes;
		scalar *minimum_size;
		unsigned recursion_depth;
		Perebor perebor;
		monitor default_monitor;
		monitor *pmonitor;
		const criteria* pcriteria;

		bool recursive(const t_rect&, t_stat&, unsigned s, t_raskroy&, t_amounts &rashod);
		bool bylen_bywid(const t_rect&, t_stat&, t_raskroy&, t_amounts &rashod);

	public:
		unsigned max_recursion_depth;

		Perebor2D(t_sizes sizes[], scalar min_size[], t_amounts &remains, criteria&);
		void set_criteria(const criteria&);
		void set_monitor(monitor&);
		void set_factory(const t_factory&);

		bool make(const t_rect&, t_stat&, t_raskroy&, t_amounts &rashod);
	};
}

#endif
