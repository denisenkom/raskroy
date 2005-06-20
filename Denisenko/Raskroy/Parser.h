#ifndef ParserH
#define ParserH

#include "common.h"
#include "types.h"

namespace Denisenko {
namespace Raskroy {


struct t_parsed_part {
	scalar pos[2];	// положение относительно нижнего-левого угла
	Rect rect;
};

struct t_parsed_cut {
	scalar pos[2];
	scalar length;
	unsigned s;	// пил по 0=длине или 1=ширине
};

typedef std::vector<t_parsed_part> t_parsed_parts;
typedef std::vector<t_parsed_cut> t_parsed_cuts;

struct t_parsed_result
{
	t_parsed_parts parts;
	t_parsed_cuts cuts;
	t_stat stat;
	Part sheet;
	unsigned amount;
};

class Parser
{
	t_parsed_result *m_pOutResult;
	scalar m_sawThickness;
	scalar m_halfSawThickness;
	scalar m_detailsSummarySquare;	// сумарная площадь деталей

	scalar Details(unsigned s, scalar pos[2], const Rect&, const t_raskroy::t_details&);
	void Recursion(scalar pos[2], const Rect&, const t_raskroy&);
public:
	scalar get_DetailsSummarySquare() {return m_detailsSummarySquare;};
	Parser(void) : m_pOutResult(0), m_sawThickness(0), m_halfSawThickness(0), m_detailsSummarySquare(0) {}
	void Parse(const t_result&, t_parsed_result&, scalar cutThickness);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // ParserH