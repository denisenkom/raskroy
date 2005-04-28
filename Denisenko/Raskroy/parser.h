#include "common.h"
#include "types.hpp"
#include "raskroy.h"

namespace Denisenko {
namespace Raskroy {

typedef std::vector<t_parsed_part> t_parsed_parts;
typedef std::vector<t_parsed_cut> t_parsed_cuts;

struct t_parsed_result
{
	t_parsed_parts parts;
	t_parsed_cuts cuts;
	t_stat stat;
	t_part sheet;
	unsigned amount;
};

class Parser
{
	t_parsed_result* poutresult;
	scalar saw_thickness, half_saw_thickness;

	scalar details(unsigned s, scalar pos[2], const t_rect&, const t_raskroy::t_details&);
	void Recursion(scalar pos[2], const t_rect&, const t_raskroy&);
public:
	scalar details_summary_square;	// сумарная площадь деталей
	Parser(void) : poutresult(0), saw_thickness(0), half_saw_thickness(0) {}
	void parse(const t_result&, t_parsed_result&, scalar cut_thickness);
};

} // namespace Denisenko
} // namespace Raskroy