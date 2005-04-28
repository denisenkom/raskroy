#include "common.h"
#include "Perebor2d.h"

// TODO: процент завершения
// TODO: есть глюк в тесте 1 на странице 1

namespace Denisenko {
namespace Raskroy {

class Raskroy {
	Perebor2d _perebor2d;

	//criteria default_criteria;
	//const criteria* pcriteria;

	t_amounts _remains;

	t_sizes _sizes[2];
	scalar _minSize[2];

	t_parts _sheets;


	void RemoveExostedSizes(void);
	bool MakeOneResult(t_result&);

public:
	bool ControlRemains;

	Raskroy(void)
		: /*pcriteria(&default_criteria),*/
			_perebor2d(_sizes, _minSize, _remains/*, default_criteria*/),
			ControlRemains(false) {}

	void SetCutWidth(double x) throw () {_perebor2d.SetCutWidth(x);}

	double GetCutWidth(void) throw () {return _perebor2d.GetCutWidth();}

	//void SetCriteria(const criteria& c) throw ()
	//{
	//	pcriteria = &c;
	//	Perebor2d.SetCriteria(c);
	//}

	bool First(const t_parts &parts, const t_parts &sheets, t_result &res)
	{
		//assert(pcriteria);
		_sheets = sheets;
		t_sizes::make_list(_sizes, parts, _remains);
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