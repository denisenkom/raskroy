//#include <iostream>
#include "raskroy.h"

namespace raskroy
{

scalar gilotine::perebor(scalar size)
{
	//if (i == perebor_other_sizes->end())
	//	return size;
	scalar register size1;
	unsigned n;
	perebor_i++;
	if (perebor_i != pperebor_sizes->end())
	{
		perebor_i--;
		n = 0;
		scalar best = size;
		size1 = size - perebor_i->size*n;
		while (size1 >= 0)
		{
			scalar remain;
			//if (size1 < perebor_minimum_size - factory.saw_thickness)
			//	remain = size1;
			//else
			//{
				perebor_i++;
				remain = perebor(size1 - factory.saw_thickness);
				perebor_i--;
			//}
			if (remain < best)
			{
				best = remain;
				perebor_i->n = n;
			}
			n++;
			size1 = size - perebor_i->size*n;
		}
		return best;
	}
	else
	{
		perebor_i--;
		n = unsigned(size/perebor_i->size);
		perebor_i->n = n;
		size1 = size - n*perebor_i->size;
		return size1 > 0 ? size1 : 0;
	}
}
}

void raskroy::gilotine::recursive(const t_list &list, t_stat &stat, unsigned s)
{
	t_stat best_stat;
	bool first = true;
	for (t_sizes_list::iterator i = sizes[s].begin(); i != sizes[s].end(); i++)
	{
		t_stat stat1(stat);
		if (i->size > list.size[s])
			continue;
		else
		{
			t_list list1;
			list1.size[s] = i->size;
			list1.size[!s] = list.size[!s];
			pperebor_sizes = &i->other_sizes;
			perebor_i = i->other_sizes.begin();
			scalar remain = perebor(list1.size[!s]);
			if (remain >= minimum_size[s].size)
			{
				list1.size[!s] = remain;
				recursive(list1, stat1, !s);
			}
			else
				stat1.sum_remain += remain*list1.size[!s];
			
			if (i->size >= list.size[s] - factory.saw_thickness)
			{
				list1.size[s] = i->size;
				stat1.sum_cut_length += list.size[!s];
			}
			else if (i->size >= list.size[s] - minimum_size[s].size - factory.saw_thickness)
			{
				list1.size[s] = i->size;
				stat1.sum_cut_length += list.size[!s];
				stat1.sum_remain += (list.size[s] - i->size - factory.saw_thickness)*list.size[!s];
			}
			else
			{
				stat1.sum_cut_length += list.size[!s];
				t_list list2(list);
				list2.size[s] = list.size[s] - i->size - factory.saw_thickness;
				bylen_bywid(list2, stat1);
			}
			if (first || pcriteria->compare(stat1, best_stat))
			{
				best_stat = stat1;
				//result.i = i;
				//result.s = s;
				first = false;
			}
		}
	}
	if (!first)
		stat = best_stat;
	else
		stat.sum_remain += list.size[0]*list.size[1];
}

void raskroy::gilotine::bylen_bywid(const t_list &list, t_stat &stat)
{
	t_stat stat1(stat), stat2(stat);
	recursive(list, stat1, 0);
	recursive(list, stat2, 1);
	if (pcriteria->compare(stat1, stat2))
	{
		stat = stat1;
	}
	else
	{
		stat = stat2;
	}
}

void raskroy::gilotine::make_materials_list(void)
{
	t_parts_list parts1(parts);
	t_parts_list lists1(lists);
	while (!parts1.empty())
	{
		t_parts_list::iterator i = parts1.begin();
		t_material mtrl;
		mtrl.id = i->material_id;
		//t_parts_list::iterator j = parts1.begin();
		while (i != parts1.end())
		{
			if (i->material_id == mtrl.id)
			{				
				mtrl.parts.push_back(*i);
				parts1.erase(i);
				i = parts1.begin();				
			}
			else
				i++;
		}
	
		t_parts_list::iterator j = lists1.begin();
		while (j != lists1.end())
		{
			if (j->material_id == mtrl.id)
			{
				mtrl.lists.push_back(*j);
				lists1.erase(j);
				j = lists1.begin();
			}
			else
				j++;
		}
		materials.push_back(mtrl);
	}
}

void raskroy::gilotine::make_sizes_lists_for_material(const t_material &material)
{
	sizes[0].clear();
	sizes[1].clear();

	for (unsigned s = 0; s <= 1; s++)
	{
		bool first = true;
		bool min_size = true;
		t_parts_list parts1(material.parts);
		while (!parts1.empty())
		{
			t_size size;
			t_parts_list::iterator i = parts1.begin();
			size.size = i->list.size[s];
			if (first || size.size < minimum_size[s].size)
			{
				min_size = true;
				minimum_size[s].size = size.size;
				first = false;
			}
			else
				min_size = false;
			while (i != parts1.end())
			{
				bool first = true;
				if (i->list.size[s] == size.size)
				{
					t_other_size other_size;
					other_size.size = i->list.size[!s];
					size.other_sizes.push_back(other_size);
					parts1.erase(i);
					i = parts1.begin();
					if (min_size && (first || other_size.size < minimum_size[s].other_size))
					{
						first = false;
						minimum_size[s].other_size = other_size.size;
					}
				}
				else
					i++;
			}
			sizes[s].push_back(size);
		}
	}
}


raskroy::gilotine::gilotine(const t_parts_list &parts, const t_parts_list &lists, const t_factory &factory/*, criteria *pcriteria*/)
	: factory(factory), parts(parts), lists(lists)/*, pcriteria(pcriteria)*/
{
}

// Raskroy start
void raskroy::gilotine::run(void)
{
	make_materials_list();
	for (t_materials_list::const_iterator mi = materials.begin(); mi != materials.end(); mi++)
	{
		make_sizes_lists_for_material(*mi);
		t_stat stat, best_stat;
		bool first = true;
		for (t_parts_list::const_iterator li = mi->lists.begin(); li != mi->lists.end(); li++)
		{
			//bylen_bywid(li->list, stat);
			//if (first || pcriteria->compare(stat, best_stat))
			//{
			//	first = false;
			//	best_stat = stat;
			//}
		}
		statistic += best_stat;
	}
}
