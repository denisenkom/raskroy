#pragma once

#include "layout2d.h"

namespace Denisenko {
namespace Raskroy {

class ResultsGenerator {
public:
	bool ControlRemains;
	ResultsGenerator(void)
		: m_remains(0), m_layout2d(m_sizes, m_minSize, &m_remains),
		ControlRemains(false)
	{
	}
	void   put_SawThickness(scalar x) throw () {m_layout2d.put_SawThickness(x);}
	scalar get_SawThickness(void) throw () {return m_layout2d.get_SawThickness();}
	void Begin(Parts &parts, const Parts &sheets);
	bool NextResult(Result &res);

	float GetPercentCompleted();

private:
	Amounts m_remains;
	Layout2d m_layout2d;
	Sizes m_sizes[2];
	scalar m_minSize[2];
	Parts m_sheets;
	Parts m_parts;
	//Parts m_inputParts;
	//Parts m_splitedParts;

	void RemoveExostedSizes(void);
	void CheckResult(const Result& result);
	//void SubstractPartsAmounts(const Amounts& amounts);
};

Parts SplitEqualParts(const Parts& parts);
//double GetEstimatedTime(const Parts& parts, const Sheet& sheet);
double GetAverageSizeA(const Parts& parts);
double GetAverageSizeB(const Parts& parts);
int Combinations(int smallSet, int fullSet);

} // namespace Denisenko
} // namespace Raskroy
