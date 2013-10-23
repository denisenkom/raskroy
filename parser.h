#ifndef ParserH
#define ParserH

#include "types.h"
#include "Result.h"

namespace Denisenko {
namespace Raskroy {


struct t_parsed_part {
	scalar pos[2];	// location relative to left-bottom corner
	Rect rect;
};

struct t_parsed_cut {
	scalar pos[2];
	scalar length;
	unsigned s;	// cut direction along 0=length or 1=width
};

typedef std::vector<t_parsed_part> t_parsed_parts;
typedef std::vector<t_parsed_cut> t_parsed_cuts;

struct t_parsed_result
{
	t_parsed_parts parts;
	t_parsed_cuts cuts;
	Stat stat;
	Part sheet;
	unsigned amount;
};

// new preferred name for class
typedef t_parsed_result ParsedResult;


class Parser
{
	t_parsed_result *m_pOutResult;
	scalar m_sawThickness;
	scalar m_halfSawThickness;
	scalar m_detailsSummarySquare;	// total parts square

	scalar Details(unsigned s, scalar pos[2], const Rect&, const OldLayoutResult::t_details&);
	void Recursion(scalar pos[2], const Rect&, const OldLayoutResult&);
public:
	scalar get_DetailsSummarySquare() {return m_detailsSummarySquare;};
	Parser(void) : m_pOutResult(0), m_sawThickness(0), m_halfSawThickness(0), m_detailsSummarySquare(0) {}
	void Parse(const t_result&, t_parsed_result&, scalar cutThickness);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // ParserH
