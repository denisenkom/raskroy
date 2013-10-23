#ifndef ParserH
#define ParserH

#include "types.h"
#include "Result.h"

namespace Denisenko {
namespace Raskroy {


struct ParsedPart {
	scalar pos[2];	// location relative to left-bottom corner
	Rect rect;
};

struct ParsedCut {
	scalar pos[2];
	scalar length;
	unsigned s;	// cut direction along 0=length or 1=width
};

typedef std::vector<ParsedPart> ParsedParts;
typedef std::vector<ParsedCut> ParsedCuts;

struct ParsedResult
{
	ParsedParts parts;
	ParsedCuts cuts;
	Stat stat;
	Part sheet;
	unsigned amount;
};


class Parser
{
	ParsedResult *m_pOutResult;
	scalar m_sawThickness;
	scalar m_halfSawThickness;
	scalar m_detailsSummarySquare;	// total parts square

	scalar Details(unsigned s, scalar pos[2], const Rect&, const OldLayoutResult::Details&);
	void Recursion(scalar pos[2], const Rect&, const OldLayoutResult&);
public:
	scalar get_DetailsSummarySquare() {return m_detailsSummarySquare;};
	Parser(void) : m_pOutResult(0), m_sawThickness(0), m_halfSawThickness(0), m_detailsSummarySquare(0) {}
	void Parse(const Result&, ParsedResult&, scalar cutThickness);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // ParserH
