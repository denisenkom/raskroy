#include <iostream>
#include "guillotine.h"

int main(void)
{
	raskroy::t_parts_list parts, lists;
	raskroy::t_part part, list;
	//list.material_id = 1;
	list.rect.size[0] = 2800;
	list.rect.size[1] = 1400;
	lists.push_back(list);
	//part.material_id = 1;
	part.rect.size[0] = 1000;
	part.rect.size[1] = 1100;
	parts.push_back(part);
	part.rect.size[0] = 800;
	part.rect.size[1] = 400;
	parts.push_back(part);

	raskroy::t_factory factory;
	factory.saw_thickness = 4;
	
	raskroy::criteria criteria;
	raskroy::Guillotine x;
	x.set_factory(factory);
	x.set_criteria(criteria);
	raskroy::t_result result;
	std::cout << "Starting raskroy\n";
	if (x.first(parts, lists, result))
	{
		while (x.next(result))
			;
		//raskroy::t_stat stat = x.getStat();
		//std::cout << "statistica: remain=" << stat.sum_remain/1000000.0f << "\ncut length=" << stat.sum_cut_length/1000.0f << std::endl;
	}
	return 0;
}
