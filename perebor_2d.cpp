namespace raskroy {

	inline perebor_2d::perebor_2d(t_sizes sizes[], scalar min_size[], t_amounts &remains, criteria &criteria)
		: recursion_depth(0), max_recursion_depth(8), pcriteria(&criteria), pmonitor(&default_monitor),
		sizes(sizes), minimum_size(min_size), remains(remains), perebor(remains, factory.saw_thickness)
	{
	}

	inline void perebor_2d::set_monitor(monitor &monitor)
	{
		pmonitor = &monitor;
	}

	inline void perebor_2d::set_factory(const t_factory &factory)
	{
		this->factory = factory;
		perebor.saw_thickness = factory.saw_thickness;
	}

	inline void perebor_2d::set_criteria(const criteria &criteria)
	{
		this->pcriteria = &criteria;
	}

	inline bool perebor_2d::make(const t_rect &rect, t_stat &stat, t_raskroy &raskroy, t_amounts &rashod)
	{
#ifndef NDEBUG
		char buf[256];
		std::string str("perebor_2d::make(rect(");
		str += gcvt(rect.size[0], 5, buf);
		str += ",";
		str += gcvt(rect.size[1], 5, buf);
		str += "))";
		MessageBox(NULL, str.c_str(), 0, 0);
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
	bool perebor_2d::recursive(const t_rect &rect, t_stat &stat, unsigned s, t_raskroy &raskroy, t_amounts &rashod)
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
	bool perebor_2d::bylen_bywid(const t_rect &rect, t_stat &stat, t_raskroy &raskroy, t_amounts &rashod)
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
}