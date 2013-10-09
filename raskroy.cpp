//#include "types.hpp"
//#include "raskroy.h"

namespace raskroy {
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

	inline void gilotine::remove_exosted_sizes(void)
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

	inline bool gilotine::make_one_raskroy_result(t_result& res)
	{
#ifndef NDEBUG
		MessageBox(NULL, "make_one_raskroy_result()", 0, 0);
#endif
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

	/*inline*/ gilotine::gilotine(void)
		: pcriteria(&default_criteria), perebor_2d(sizes, minimum_size, remains, default_criteria)
	{
	}

	inline void gilotine::set_factory(const t_factory &factory)
	{
		perebor_2d.set_factory(factory);
	}

	inline void gilotine::set_recursion_max_depth(unsigned depth)
	{
		perebor_2d.max_recursion_depth = depth;
	}

	inline void gilotine::set_criteria(const criteria &criteria)
	{
		assert(&criteria);
		pcriteria = &criteria;
		perebor_2d.set_criteria(criteria);
	}

	inline void gilotine::set_monitor(monitor &monitor)
	{
		perebor_2d.set_monitor(monitor);
	}

	inline t_stat gilotine::get_common_stat(void)
	{
		return common_stat;
	}

	// Raskroy start
	inline bool gilotine::first(const t_parts& parts, const t_parts& sheets, t_result& res)
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
			str += ultoa(i->amount, buf, 10);
			str += i->rotate ? "true" : "false";
			str += ")";
		}
		str += "})";
		MessageBox(NULL, str.c_str(), 0, 0);
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

	inline bool gilotine::next(t_result& res)
	{
#ifndef NVERBOSE
		//for (t_amounts::const_iterator i = remains.begin(); i != remains.end(); i++)
		//	std::cout << *i << std::endl;
#endif
		assert(pcriteria/* && pmonitor*/);
		return make_one_raskroy_result(res);
	}
}