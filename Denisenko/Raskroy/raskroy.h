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

	t_sizes m_sizes[2];
	scalar m_minSize[2];

	t_parts m_sheets;


	void RemoveExostedSizes(void);
	bool MakeOneResult(t_result&);

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

	bool First(const t_parts &parts, const t_parts &sheets, t_result &res)
	{
		//assert(pcriteria);
		m_sheets = sheets;
		t_sizes::make_list(m_sizes, parts, m_remains);
		return MakeOneResult(res);
	}

	bool Next(t_result &res)
	{
		//assert(pcriteria);
		return MakeOneResult(res);
	}
};

} // namespace Denisenko
} // namespace Raskroy