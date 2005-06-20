#include "common.h"
#include "Perebor2d.h"

// TODO: процент завершения
// TODO: есть глюк в тесте 1 на странице 1

namespace Denisenko {
namespace Raskroy {

class Raskroy {
	Perebor2d m_perebor2d;
	Amounts m_remains;
	Sizes m_sizes[2];
	scalar m_minSize[2];
	Parts m_sheets;

	void RemoveExostedSizes(void);

public:
	bool ControlRemains;
	Raskroy(void) : m_perebor2d(m_sizes, m_minSize, m_remains), ControlRemains(false) {}
	void   put_SawThickness(double x) throw () {m_perebor2d.put_SawThickness(x);}
	double get_SawThickness(void) throw () {return m_perebor2d.get_SawThickness();}
	void Begin(Parts &parts, const Parts &sheets);
	bool NextResult(t_result &res);
};

} // namespace Denisenko
} // namespace Raskroy