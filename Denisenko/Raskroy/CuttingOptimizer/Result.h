#ifndef ResultH
#define ResultH

#include "types.h"

namespace Denisenko {
namespace Raskroy {

struct t_raskroy {
	struct t_detail {scalar size; unsigned num;};
	typedef std::list<t_detail> t_details;

	unsigned s; // разрез проходит перпендикул€рно этой стороне
	unsigned kratnostj;
	scalar cut;
	t_details details;

	t_raskroy() : premain(0), precurse(0) {}
	t_raskroy(const t_raskroy &orig)
		: s(orig.s),
		kratnostj(orig.kratnostj),
		cut(orig.cut),
		details(orig.details),
		premain(orig.premain),
		precurse(orig.precurse)
	{
		orig.premain = 0;
		orig.precurse = 0;
	}

	~t_raskroy() {
		delete premain;
		delete precurse;
	}

	void set(int s, unsigned kratnostj, scalar cut, t_details &details, t_raskroy *premain, t_raskroy *precurse);
	t_raskroy& operator = (const t_raskroy &orig);
	void attachRemain(t_raskroy &remain);
	void attachRecurse(t_raskroy &recurse);
	t_raskroy * watchRemain(void) const {return premain;}
	t_raskroy * watchRecurse(void) const {return precurse;}

	void CheckAndCalcStat(scalar cutThickness, const Rect& rect, Stat* outStat) const;

private:
	mutable t_raskroy *premain;
	mutable t_raskroy *precurse;
};

class t_result {
public:
	t_raskroy raskroy;
	Parts::iterator sheet;
	Stat Statistics;
	unsigned amount;

	t_result(void) : amount(0) {}
};

} // namespace Denisenko
} // namespace Raskroy

#endif // ResultH