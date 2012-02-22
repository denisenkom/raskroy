#include "guillotine.h"
#include <algorithm>

using namespace std;

namespace raskroy {

	Perebor::Perebor(t_amounts &remains, scalar saw_thickness)
		: remains(remains), saw_thickness(saw_thickness)
	{
	}

	// Рекурсивный перебор
	// Параметры:
	//		[i] size - размер на котором нужно расположить детали
	//		[o] rashod - количество расположенных деталей
	scalar Perebor::recursive(scalar size, t_amounts &rashod)
	{
		//if (i == perebor_other_sizes->end())
		//	return size;
		scalar register size1;
		//t_amounts best_amounts(amounts.size());
		unsigned n;
		if (i != end)
		{
			n = 0;
			scalar best = size;
			size1 = size;
			t_amounts rashod1;
			rashod1.resize(rashod.size());
			std::fill(rashod1.begin(), rashod1.end(), 0);
			unsigned remain = i->num(remains);
			while (size1 > saw_thickness && n < remain)
			{
				scalar remain;
				//if (size1 < perebor_minimum_size - factory.saw_thickness)
				//	remain = size1;
				//else
				//{
					i++;
					remain = recursive(size1, rashod1);
					i--;
				//}
				if (remain < best)
				{
					best = remain;
					//perebor_i->n = n;
					std::copy(rashod1.begin(), rashod1.end(), rashod.begin());
					i->make_rashod(rashod, n, remains);
				}
				n++;
				size1 = size - (i->size + saw_thickness)*n;
			}
			//amounts = best_amounts;
			return best;
		}
		else
		{
			n = unsigned((size + saw_thickness)/(i->size + saw_thickness));
			unsigned remain = i->num(remains);
			if (n > remain)
				n = remain;
			i->make_rashod(rashod, n, remains);
			size1 = size - n*(i->size + saw_thickness);
			return size1;
		}
	}

	// Перебор деталей одного базисного размера на другом размере с контролем остатков
	// Параметры:
	//		[i] size - базисный размер
	//		[i] other_size - перпендикулярный размер
	//		[o] stat - статистика
	//		[o] raskroy - расположение деталей
	//		[o] rashod - расход деталей
	// Возвращает true если хотя бы одна деталь установлена
	bool Perebor::make(const t_size &size, scalar other_size, t_stat &stat, t_raskroy &raskroy, t_amounts &rashod)
	{
		if (other_size < size.other_sizes.watchMin()->size)
			return false;

		unsigned nums = 0;
		i = size.other_sizes.begin();
		end = size.other_sizes.end();
		end--;
		scalar remain = recursive(other_size, rashod);
		if (remain < other_size)
		{
			for (i = size.other_sizes.begin(); i != size.other_sizes.end(); i++)
			{
				unsigned rashodi = i->num(rashod);
				if (rashodi > 0)
				{
					t_raskroy::t_detail detail;
					detail.size = i->size;
					detail.num = rashodi;
					raskroy.details.push_back(detail);
					nums += rashodi;
				}
			}
			stat.sum_cut_length = size.size*(nums);
			stat.sum_remain = size.size*saw_thickness;
			this->remain = remain;
			return true;
		}
		else
			return false;
	}

		Perebor2D::Perebor2D(t_sizes sizes[], scalar min_size[], t_amounts &remains, criteria &criteria)
		: recursion_depth(0), max_recursion_depth(8), pcriteria(&criteria), pmonitor(&default_monitor),
		sizes(sizes), minimum_size(min_size), remains(remains), perebor(remains, factory.saw_thickness)
	{
	}

	void Perebor2D::set_monitor(monitor &monitor)
	{
		pmonitor = &monitor;
	}

	void Perebor2D::set_factory(const t_factory &factory)
	{
		this->factory = factory;
		perebor.saw_thickness = factory.saw_thickness;
	}

	void Perebor2D::set_criteria(const criteria &criteria)
	{
		this->pcriteria = &criteria;
	}

	bool Perebor2D::make(const t_rect &rect, t_stat &stat, t_raskroy &raskroy, t_amounts &rashod)
	{
#ifndef NDEBUG
		char buf[256];
		std::string str("Perebor2D::make(rect(");
		str += gcvt(rect.size[0], 5, buf);
		str += ",";
		str += gcvt(rect.size[1], 5, buf);
		str += "))";
		cout << str;
#endif
		return bylen_bywid(rect, stat, raskroy, rashod);
	}

	// Рекурсивный перебор всех делений листа по длине/ширине (s=0/1) с возможностью кратного расположения
	// Параметры:
	//		[i] list - размеры листа
	//		[i/o] stat - статистика
	//		[i] s - выбор направления раскроя по длине/ширине s=0/1
	//		[o] raskroy - раскрой листа
	//		[o] rashod - расход деталей
	//
	bool Perebor2D::recursive(const t_rect &rect, t_stat &stat, unsigned s, t_raskroy &raskroy, t_amounts &rashod)
	{
		if (rect.size[s] < minimum_size[s])
			goto nothing;
		{bool first = true;
		t_stat best_stat;
		t_amounts best_rashod;
		t_amounts rashod1;
		rashod1.resize(remains.size());
		for (t_sizes::iterator i = sizes[s].begin(); i != sizes[s].end(); i++)
		{
			t_stat stat1;
			if (i->size > rect.size[s])
				continue;
			else
			{
				t_raskroy raskroy1;
				std::fill(rashod1.begin(), rashod1.end(), 0);
				raskroy1.cut = i->size;
				raskroy1.s = s;
				stat1.sum_cut_length += rect.size[!s];
				stat1.sum_remain += rect.size[!s]*factory.saw_thickness;

				if (!perebor.make(*i, rect.size[!s], stat1, raskroy1, rashod1))
					continue;

				unsigned size_krat = (rect.size[s] + factory.saw_thickness)/(i->size + factory.saw_thickness);
				unsigned kol_krat = remains/rashod1;
				if (size_krat > kol_krat)
					raskroy1.kratnostj = kol_krat;
				else
					raskroy1.kratnostj = size_krat;

				assert(raskroy1.kratnostj);

				if (raskroy1.kratnostj > 1)
				{
					rashod1 *= raskroy1.kratnostj;
					stat1 *= raskroy1.kratnostj;
				}

				{
					t_rect rect1;
					rect1.size[s] = i->size*raskroy1.kratnostj;
					rect1.size[!s] = perebor.remain;
					t_raskroy remain_raskroy;
					if (bylen_bywid(rect1, stat, remain_raskroy, rashod1))
					{
						raskroy1.attachRemain(remain_raskroy);
					}
				}

				stat1 += stat;

				if (!first && pcriteria->compare(&best_stat, &stat1))	// already bad
					continue;
			
				if ((i->size + factory.saw_thickness)*raskroy1.kratnostj > rect.size[s] - minimum_size[s])
				{
					stat1.sum_remain += (rect.size[s] - (i->size + factory.saw_thickness)*raskroy1.kratnostj)*rect.size[!s];
				}
				else
				{
					t_rect rect2(rect);
					rect2.size[s] = rect.size[s] - (i->size + factory.saw_thickness)*raskroy1.kratnostj;
					t_raskroy recurse_raskroy;
					if (bylen_bywid(rect2, stat1, recurse_raskroy, rashod1))
					raskroy1.attachRecurse(recurse_raskroy);
				}

				if (first || pcriteria->compare(&stat1, &best_stat))
				{
					best_stat = stat1;
					raskroy = raskroy1;
					best_rashod = rashod1;
					first = false;
				}
			}
		}
		if (!first)
		{
			stat = best_stat;
			rashod = best_rashod;
			return true;
		}
		else
		{
			goto nothing;
		}
		}
	nothing:
		stat.sum_remain += rect.size[0]*rect.size[1];
		stat.remains_num++;
		return false;
	}

	// Раскрой листа по длине и по ширине, возвращает лучший выриант
	// Параметры:
	//		[i] rect - размер листа
	//		[i/o] stat - статистика
	//		[o] raskroy - раскрой листа
	//		[i/o] rashod - расход деталей
	//
	bool Perebor2D::bylen_bywid(const t_rect &rect, t_stat &stat, t_raskroy &raskroy, t_amounts &rashod)
	{
		recursion_depth++;
		if (recursion_depth > max_recursion_depth)
			goto nothing;

		{
		t_stat stat1(stat), stat2(stat);
		t_amounts rashod1, rashod2;
		t_raskroy raskroy1, raskroy2;

		remains -= rashod;
		if (recursion_depth == 1)
		{
			assert(pmonitor);
			pmonitor->update_progress(0);
		}
		bool rb1 = recursive(rect, stat1, 0, raskroy1, rashod1);
		bool rb2 = false;
		if (rb1)
		{
			/*unsigned progress_increment = 100/(sheets_num*(1<<recursion_depth));
			progress_base += progress_increment;
			if (recursion_depth <= 6)	// для больших значений изменение прогресса < 1
			{
				assert(pmonitor);
				pmonitor->update_progress(progress_base);
			}*/
			if (recursion_depth == 1)
			{
				assert(pmonitor);
				pmonitor->update_progress(50);
			}
			rb2 = recursive(rect, stat2, 1, raskroy2, rashod2);
			/*progress_base += progress_increment;
			if (recursion_depth <= 7)
			{
				assert(pmonitor);
				pmonitor->update_progress(progress_base);
			}*/
		}
		if (recursion_depth == 1)
		{
			assert(pmonitor);
			pmonitor->update_progress(100);
		}
		remains += rashod;
		if (rb1 && rb2)
		{
			if (pcriteria->compare(&stat1, &stat2))
			{
				stat = stat1;
				raskroy = raskroy1;
				rashod += rashod1;
			}
			else
			{
				stat = stat2;
				raskroy = raskroy2;
				rashod += rashod2;
			}
			recursion_depth--;
			return true;
		}
		else
			goto nothing;
		}

	nothing:
		stat.sum_remain += rect.size[0]*rect.size[1];
		stat.remains_num++;
		recursion_depth--;
		return false;
	}

	class sizes_list_maker {
		bool first;
		t_sizes* sizes;
		scalar* minimum_size;
		void add_part(unsigned s, const t_min_part &part);
	public:
		void make(const t_min_parts&, t_sizes* sizes, scalar* minimum_size);
	};

	inline void sizes_list_maker::add_part(unsigned s, const t_min_part &part)
	{
		t_sizes::iterator sizei = sizes[s].find(part.rect.size[s]);
		if (sizei != sizes[s].end())
		{
			t_other_sizes::iterator other_sizei = sizei->other_sizes.find(part.rect.size[!s]);
			if (other_sizei != sizei->other_sizes.end())
				other_sizei->parts.push_back(part);
			else
				sizei->other_sizes.add_other_size(s, part);
		}
		else
		{
			sizes[s].add_size(s, part);
			if (first || minimum_size[s] > part.rect.size[s])
			{
				first = false;
				minimum_size[s] = part.rect.size[s];
			}
		}
	}

	inline void fn(t_size &s) {s.other_sizes.prepare();}

	inline void sizes_list_maker::make(const t_min_parts &parts, t_sizes* sizes, scalar* minimum_size)
	{
		this->sizes = sizes;
		this->minimum_size = minimum_size;
		sizes[0].clear();
		sizes[1].clear();

		unsigned s;
		for (s = 0; s <= 1; s++)
		{
			first = true;
			for (t_min_parts::const_iterator parti = parts.begin(); parti != parts.end(); parti++)
			{
				add_part(s, *parti);
				if (parti->rotate/* || material.rotate*/)
				{
					t_min_part rotpart(*parti);
					rotpart.rect.size[0] = parti->rect.size[1];
					rotpart.rect.size[1] = parti->rect.size[0];
					add_part(s, rotpart);
				}
			}
			/*if (material.rotate)
				s++;	// skip */
		}

		for (s = 0; s <= 1; s++)
		{
			std::for_each(sizes[s].begin(), sizes[s].end(), fn);
			//for (t_sizes::iterator sizei = sizes[s].begin(); sizei != sizes[s].end(); sizei++)
			//	sizei->other_sizes.prepare();
		}
		/*for (t_sizes::iterator sizei0 = sizes[0].begin(); sizei0 != sizes[0].end(); sizei0++)
		{
			for (t_other_sizes::iterator osi = sizei0->other_sizes.begin(); osi != sizei0->other_sizes.end(); osi++)
			{
				remains.push_back(osi->n);
				osi->offset = remains.size()-1;
			}
			sizei0->other_sizes.prepare();
		}
		for (t_sizes::iterator sizei1 = sizes[1].begin(); sizei1 != sizes[1].end(); sizei1++)
		{
			for (t_other_sizes::iterator osi = sizei1->other_sizes.begin(); osi != sizei1->other_sizes.end(); osi++)
				osi->offset = sizes[0].find(osi->size)->other_sizes.find(sizei1->size)->offset;
			sizei1->other_sizes.prepare();
		}*/
	}

	inline void Guillotine::remove_exosted_sizes(void)
	{
		for (unsigned s = 0; s <= 1; s++)
		{
			t_sizes::iterator sizei = sizes[s].begin();
			while (sizei != sizes[s].end())
			{
				t_other_sizes::iterator osi = sizei->other_sizes.begin();
				while (osi != sizei->other_sizes.end())
				{
					if (osi->num(remains) == 0)
					{
						sizei->other_sizes.erase(osi);
						osi = sizei->other_sizes.begin();
					}
					else
						osi++;
				}
				if (sizei->other_sizes.empty())
				{
					sizes[s].erase(sizei);
					sizei = sizes[s].begin();
				}
				else
					sizei++;
			}
		}
	}

	inline bool Guillotine::make_one_raskroy_result(t_result& res)
	{
		t_raskroy raskroy;
		t_result best_result;
		//best_result.torchevka = factory.
		t_amounts rashod;
		rashod.resize(remains.size());

		// проверить остались ли детали
		for (t_amounts::const_iterator remainsi = remains.begin(); remainsi != remains.end(); remainsi++)
			if (*remainsi > 0)
				goto contine_raskroy;

		// детали кончились
		return false;

		contine_raskroy:
		bool first = true;
		//sheets_num = sheets.size();
		for (t_parts::iterator si = sheets.begin(); si != sheets.end(); si++)
		{
			t_stat stat;
			stat.clear();
			std::fill(rashod.begin(), rashod.end(), 0);
			if (perebor_2d.make(si->rect, stat, raskroy, rashod))
				if (first || pcriteria->compare(&stat, &best_result.stat))
				{
#ifndef NVERBOSE
					std::cout << std::endl;
					{for (t_amounts::const_iterator i = remains.begin(); i != remains.end(); i++)
						std::cout << *i << " ";}
					std::cout << std::endl;
					{for (t_amounts::const_iterator i = rashod.begin(); i != rashod.end(); i++)
						std::cout << *i << " ";}
					std::cout << std::endl;
					//std::cout << "best_result.ammount=" << best_result.amount << std::endl;
#endif
					best_result.amount = remains/rashod;
					assert(best_result.amount);
					//if (control_sheet_remains)
					//{
						if (best_result.amount > si->amount)	// недостаточно листов
							continue;
					//}
					first = false;
					best_result.stat = stat;
					best_result.raskroy = raskroy;
					best_result.sheet = si;
					assert(best_result.amount);
				}
		}
		if (first)
			throw err_cannot_set_parts();

#ifndef NVERBOSE
		std::cout << "best_result.ammount=" << best_result.amount << std::endl;
		{for (t_amounts::const_iterator i = rashod.begin(), j = remains.begin(); i != rashod.end(); i++, j++)
			std::cout << *j << "-" << *i << "*" << best_result.amount << std::endl;}
#endif
		remains -= rashod*best_result.amount;
#ifndef NVERBOSE
		std::cout << best_result.amount << std::endl;
		{for (t_amounts::const_iterator i = remains.begin(); i != remains.end(); i++)
			std::cout << *i << std::endl;}
#endif
		remove_exosted_sizes();
		common_stat += best_result.stat;
		//if (control_sheet_remains)
		//{
			best_result.sheet->amount -= best_result.amount;
		//}
		res = best_result;
		return true;
	}

	Guillotine::Guillotine(void)
		: pcriteria(&default_criteria), perebor_2d(sizes, minimum_size, remains, default_criteria)
	{
	}

	void Guillotine::set_factory(const t_factory &factory)
	{
		perebor_2d.set_factory(factory);
	}

	void Guillotine::set_recursion_max_depth(unsigned depth)
	{
		perebor_2d.max_recursion_depth = depth;
	}

	void Guillotine::set_criteria(const criteria &criteria)
	{
		assert(&criteria);
		pcriteria = &criteria;
		perebor_2d.set_criteria(criteria);
	}

	void Guillotine::set_monitor(monitor &monitor)
	{
		perebor_2d.set_monitor(monitor);
	}

	t_stat Guillotine::get_common_stat(void)
	{
		return common_stat;
	}

	// Raskroy start
	bool Guillotine::first(const t_parts& parts, const t_parts& sheets, t_result& res)
	{
		assert(pcriteria);

#ifndef NDEBUG
		std::string str("first({");
		t_parts::const_iterator i = sheets.begin();
		for (; i != sheets.end(); i++)
		{
			char buf[256];
			str += gcvt(i->rect.size[0], 5, buf);
			str += gcvt(i->rect.size[1], 5, buf);
			str += _ultoa(i->amount, buf, 10);
			str += i->rotate ? "true" : "false";
			str += ")";
		}
		str += "})";
		std::cout << str;
#endif

		this->sheets = sheets;
		common_stat.clear();

		remains.resize(parts.size());
		t_min_parts min_parts;
		unsigned offset = 0;
		t_amounts::iterator remaini = remains.begin();
		for (t_parts::const_iterator parti = parts.begin(); parti != parts.end(); parti++, remaini++, offset++)
		{
			*remaini = parti->amount;
			t_min_part min_part;
			min_part.rect = parti->rect;
			min_part.rotate = parti->rotate;
			min_part.offset = offset;
			min_parts.push_back(min_part);
		}

		sizes_list_maker sizes_list_maker;
		sizes_list_maker.make(min_parts, sizes, minimum_size);
		return make_one_raskroy_result(res);
	}

	bool Guillotine::next(t_result& res)
	{
#ifndef NVERBOSE
		//for (t_amounts::const_iterator i = remains.begin(); i != remains.end(); i++)
		//	std::cout << *i << std::endl;
#endif
		assert(pcriteria/* && pmonitor*/);
		return make_one_raskroy_result(res);
	}


scalar parser::details(unsigned s, scalar pos[2], const t_rect &rect, const t_raskroy::t_details &details)
{
	scalar acc = 0;
	for (t_raskroy::t_details::const_iterator i = details.begin(); i != details.end(); i++)
		for (unsigned n = 0; n < i->num; n++)
		{
			t_parsed_part part;
			part.pos[s] = pos[s];
			part.pos[!s] = pos[!s] + acc;
			part.rect.size[s] = rect.size[s];
			part.rect.size[!s] = i->size;

			//part.part = 
			assert(poutresult);
			poutresult->parts.push_back(part);
			acc += i->size;
			if (n < i->num-1)
			{
				t_parsed_cut cut;
				cut.pos[s] = pos[s];
				cut.pos[!s] = pos[!s] + acc + half_saw_thickness;
				cut.s = s;
				cut.length = rect.size[s];
				assert(poutresult);
				poutresult->cuts.push_back(cut);
				acc += saw_thickness;
			}
		}

	return acc;
}

void parser::recursive(scalar pos[2], const t_rect &rect, const t_raskroy &raskroy)
{
	t_parsed_cut cut;
	cut.s = !raskroy.s;
	cut.length = rect.size[!raskroy.s];
	cut.pos[!raskroy.s] = pos[!raskroy.s];
	cut.pos[raskroy.s] = pos[raskroy.s] + raskroy.cut*raskroy.kratnostj + half_saw_thickness;
	assert(poutresult);
	poutresult->cuts.push_back(cut);
	scalar remain=0;
	scalar pos1[2];
	//raskroy_api::scalar acc = 0;
	pos1[0] = pos[0];
	pos1[1] = pos[1];
	for (unsigned k = 0; k < raskroy.kratnostj; k++)
	{
		t_rect rect1(rect);
		rect1.size[raskroy.s] = raskroy.cut;
		remain = details(raskroy.s, pos1, rect1, raskroy.details);
		pos1[raskroy.s] += raskroy.cut + saw_thickness;

		if (k < raskroy.kratnostj-1)
		{
			cut.s = !raskroy.s;
			cut.length = remain;
			cut.pos[!raskroy.s] = pos1[!raskroy.s];
			cut.pos[raskroy.s] = pos1[raskroy.s] - half_saw_thickness;
			assert(poutresult);
			poutresult->cuts.push_back(cut);
		}
	}

	cut.pos[raskroy.s] = pos[raskroy.s];
	cut.pos[!raskroy.s] = pos[!raskroy.s] + remain + half_saw_thickness;
	cut.s = raskroy.s;
	cut.length = raskroy.cut*raskroy.kratnostj;
	assert(poutresult);
	poutresult->cuts.push_back(cut);

	if (raskroy.watchRemain())
	{
		t_rect rect1;
		rect1.size[raskroy.s] = raskroy.cut*raskroy.kratnostj;
		rect1.size[!raskroy.s] = rect.size[!raskroy.s]-remain;
		pos1[raskroy.s] = pos[raskroy.s];
		pos1[!raskroy.s] = pos[!raskroy.s] + remain;
		recursive(pos1, rect1, *raskroy.watchRemain());
	}

	if (raskroy.watchRecurse())
	{
		t_rect rect1(rect);
		rect1.size[raskroy.s] = rect.size[raskroy.s] - (raskroy.cut+saw_thickness)*raskroy.kratnostj;
		pos1[raskroy.s] = pos[raskroy.s] + (raskroy.cut+saw_thickness)*raskroy.kratnostj;
		pos1[!raskroy.s] = pos[!raskroy.s];
		recursive(pos1, rect1, *raskroy.watchRecurse());
	}
}

void parser::parse(const t_result& result1, t_parsed_result& result2, scalar saw_thickness)
{
	this->saw_thickness = saw_thickness;
	half_saw_thickness = saw_thickness/2;

	poutresult = &result2;
	assert(poutresult);
	poutresult->cuts.clear();
	assert(poutresult);
	poutresult->parts.clear();
	result2.amount = result1.amount;
	result2.stat = result1.stat;
	result2.sheet = *result1.sheet;
	scalar pos[2] = {0, 0};
	recursive(pos, result1.sheet->rect, result1.raskroy);
}
}
