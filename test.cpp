#include <iostream>
#include "raskroy.h"

int main(void)
{
	raskroy::t_parts_list parts, lists;
	raskroy::t_part part, list;
	list.material_id = 1;
	list.list.size[0] = 2800;
	list.list.size[1] = 1400;
	lists.push_back(list);
	part.material_id = 1;
	part.list.size[0] = 1000;
	part.list.size[1] = 1100;
	parts.push_back(part);
	part.list.size[0] = 800;
	part.list.size[1] = 400;
	parts.push_back(part);

	raskroy::t_factory factory;
	factory.saw_thickness = 4;
	
	raskroy::criteria *pcriteria = new raskroy::criteria();
	raskroy::gilotine x(parts, lists, factory, pcriteria);
	std::cout << "Starting raskroy\n";
	x.run();
	raskroy::t_stat stat = x.getStat();
	std::cout << "statistica: remain=" << stat.sum_remain/1000000.0f << "\ncut length=" << stat.sum_cut_length/1000.0f << std::endl;
	return 0;
}

