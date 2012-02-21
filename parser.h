#ifndef RASKROY_PARSER_H
#define RASKROY_PARSER_H

#include "types.hpp"
#include "common.h"

namespace raskroy {
	typedef std::vector<t_parsed_part> t_parsed_parts;
	typedef std::vector<t_parsed_cut> t_parsed_cuts;

	struct t_parsed_result {
		t_parsed_parts parts;
		t_parsed_cuts cuts;
		t_stat stat;
		t_part sheet;
		unsigned amount;
	};

	class parser {
		t_parsed_result* poutresult;
		scalar saw_thickness, half_saw_thickness;

		scalar details(unsigned s, scalar pos[2], const t_rect&, const t_raskroy::t_details&);
		void recursive(scalar pos[2], const t_rect&, const t_raskroy&);
	public:
		parser(void) : poutresult(0), saw_thickness(0), half_saw_thickness(0) {}
		void parse(const t_result&, t_parsed_result&, scalar cut_thickness);
	};
}

#endif	// RASKROY_PARSER_H