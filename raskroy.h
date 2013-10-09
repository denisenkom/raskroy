#ifndef RASKROY_H_INCLUDED
#define RASKROY_H_INCLUDED

#include <list>
//#include <set>
#include <vector>
#include <memory>
#include <exception>
#include <assert.h>
#include "types.hpp"

// TODO: процент завершения
// TODO: есть глюк в тесте 1 на странице 1

#include "common.h"
#include "perebor_2d.h"

namespace raskroy {

	class gilotine {
		perebor_2d perebor_2d;

		criteria default_criteria;
		const criteria* pcriteria;

		t_amounts remains;

		t_sizes sizes[2];
		scalar minimum_size[2];

		t_parts sheets;

		t_stat common_stat;

		void remove_exosted_sizes(void);
		bool make_one_raskroy_result(t_result&);

	public:
		gilotine(void);

		void set_factory(const t_factory&);
		void set_recursion_max_depth(unsigned);
		void set_monitor(monitor&);
		void set_criteria(const criteria&);
		t_stat get_common_stat(void);

		bool first(const t_parts& parts, const t_parts& sheets, t_result&);
		bool next(t_result&);
	};
}

#endif	// RASKROY_H_INCLUDED
