#include "common.h"
#include "perebor_2d.h"

// TODO: процент завершения
// TODO: есть глюк в тесте 1 на странице 1

namespace Denisenko {
namespace Raskroy {

class Raskroy {
	perebor_2d perebor_2d;

	//criteria default_criteria;
	//const criteria* pcriteria;

	t_amounts remains;

	t_sizes sizes[2];
	scalar minimum_size[2];

	t_parts sheets;


	void remove_exosted_sizes(void);
	bool make_one_raskroy_result(t_result&);

public:
	bool control_sheet_remains;
	t_stat common_stat;

	Raskroy(void)
		: /*pcriteria(&default_criteria),*/
			perebor_2d(sizes, minimum_size, remains/*, default_criteria*/),
			control_sheet_remains(false)
	{
	}

	void set_cut_width(double x) throw ()
	{
		perebor_2d.set_cut_width(x);
	}

	double get_cut_width(void) throw ()
	{
		return perebor_2d.get_cut_width();
	}

	void set_recursion_max_depth(unsigned depth) throw ()
	{
		perebor_2d.max_recursion_depth = depth;
	}

	unsigned get_recursion_max_depth(void) throw ()
	{
		return perebor_2d.max_recursion_depth;
	}

	void set_monitor(monitor& monitor) throw ()
	{
		perebor_2d.set_monitor(monitor);
	}

	/*void set_criteria(const criteria& c) throw ()
	{
		pcriteria = &c;
		perebor_2d.set_criteria(c);
	}*/

	bool first(const t_parts& parts, const t_parts& sheets, /*[out]*/ t_result& res)
	{
		/*assert(pcriteria);*/
		this->sheets = sheets;
		common_stat = t_stat(0);
		t_sizes::make_list(sizes, parts, remains);
		return make_one_raskroy_result(res);
	}

	bool next(/*[out]*/ t_result& res)
	{
		/*assert(pcriteria);*/
		return make_one_raskroy_result(res);
	}
};

} // namespace Denisenko
} // namespace Raskroy