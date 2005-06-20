#include "common.h"
#include "Perebor2d.h"

// TODO: процент завершения
// TODO: есть глюк в тесте 1 на странице 1

namespace Denisenko {
namespace Raskroy {

class Raskroy {
	Perebor2d m_perebor2d;

	//criteria default_criteria;
	//const criteria* pcriteria;

	t_amounts m_remains;

	Sizes m_sizes[2];
	scalar m_minSize[2];

	Parts m_sheets;


	void RemoveExostedSizes(void);

public:
	bool ControlRemains;

	Raskroy(void)
		: /*pcriteria(&default_criteria),*/
			m_perebor2d(m_sizes, m_minSize, m_remains/*, default_criteria*/),
			ControlRemains(false) {}

	void put_SawThickness(double x) throw () {m_perebor2d.put_SawThickness(x);}
	double get_SawThickness(void) throw () {return m_perebor2d.get_SawThickness();}

	//void SetCriteria(const criteria& c) throw ()
	//{
	//	pcriteria = &c;
	//	Perebor2d.SetCriteria(c);
	//}

	void Begin(const Parts &parts, const Parts &sheets) {
		//assert(pcriteria);
		m_sheets = sheets;
		Sizes::MakeList(m_sizes, parts, m_remains);
	}

	bool NextResult(t_result &res);
};

} // namespace Denisenko
} // namespace Raskroy