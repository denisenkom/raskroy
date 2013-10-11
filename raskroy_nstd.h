ifndef RASKROY_H_INCLUDED
#define RASKROY_H_INCLUDED

#include <list>
#include <string>
#include <vector>
#include <memory>
#include <assert.h>

// TODO: ѕрикрутить монитор (показывает процент завершени€ каждого листа), исправить глюки.
// TODO:  онтроль остатков листов.
//		алгоритм говно!!!

namespace raskroy {

	typedef float scalar;
	typedef struct s_list {scalar size[2];} t_list;

	typedef struct s_part {unsigned id; t_list list; bool rotate;
		unsigned ammount; unsigned material_id;
        bool operator==(const s_part&);
        bool operator<(const s_part&);} t_part;
	typedef std::list<t_part> t_parts;

	typedef struct s_material {unsigned id; t_parts parts; t_parts lists;
    	bool operator==(const s_material&); bool operator<(const s_material&);} t_material;
	typedef std::list<t_material> t_materials;

    class runtime_error {
    	std::string err;
    public:
    	runtime_error(std::string err)
        	: err(err)
        {
        }
    };

	struct t_raskroy {
		struct t_detail {scalar size; unsigned num; bool operator==(const t_detail&); bool operator<(const t_detail&);};
		typedef std::list<t_detail> t_details;

		unsigned s, kratnostj;
		scalar cut;
		t_details details;

		t_raskroy()
			: premain(0), precurse(0) {}

		t_raskroy(const t_raskroy &orig)
			: s(orig.s), kratnostj(orig.kratnostj), cut(orig.cut), details(orig.details), premain(orig.premain), precurse(orig.precurse)
		{
			const_cast<t_raskroy*>(orig.premain) = 0;
			const_cast<t_raskroy*>(orig.precurse) = 0;
		}

		~t_raskroy() {
			delete premain;
			delete precurse;
		}

		t_raskroy& operator = (const t_raskroy &orig)
		{
			delete premain;
			delete precurse;

			s = orig.s;
			kratnostj = orig.kratnostj;
			cut = orig.cut;
			details = orig.details;
			premain = orig.premain;
			precurse = orig.precurse;

			orig.premain = 0;
			orig.precurse = 0;

            return *this;
		}

        bool operator==(const t_raskroy&);
        bool operator<(const t_raskroy&);

		void attachRemain(t_raskroy &remain) {
			if (premain)
				*premain = remain;
			else
				premain = new t_raskroy(remain);
		}

		void attachRecurse(t_raskroy &recurse) {
			if (precurse)
				*precurse = recurse;
			else
				precurse = new t_raskroy(recurse);
		}

		t_raskroy * watchRemain(void) const {
			return premain;
		}

		t_raskroy * watchRecurse(void) const {
			return precurse;
		}

	private:
		//t_result(const t_result &orig) {}
		mutable t_raskroy *premain;
		mutable t_raskroy *precurse;
	};

	typedef struct s_factory {scalar saw_thickness; bool operator==(const s_factory&);} t_factory;
	struct t_stat {
		scalar sum_cut_length;
		scalar sum_remain;
		unsigned remains_num;

		t_stat() : sum_cut_length(0), sum_remain(0) {}
		t_stat(scalar sum_cut_length, scalar sum_remain)
			: sum_cut_length(sum_cut_length), sum_remain(sum_remain) {}

		t_stat& operator += (const t_stat& stat) {
			sum_cut_length += stat.sum_cut_length;
			sum_remain += stat.sum_remain;
			remains_num += stat.remains_num;
			return *this;
		}

		t_stat& operator *= (unsigned k) {
			sum_cut_length *= k;
			sum_remain *= k;
			remains_num *= k;
			return *this;
		}

        bool operator==(const t_stat&);
        bool operator<(const t_stat&);

		void clear(void) {
			sum_cut_length = 0;
			sum_remain = 0;
			remains_num = 0;
		}
	};

	class criteria {
	public:
		// return true if a better than b
		virtual bool compare(t_stat a, t_stat b) const
		{
			return (a.sum_remain < b.sum_remain
				|| a.sum_remain == b.sum_remain && a.remains_num < b.remains_num
				|| a.sum_remain == b.sum_remain && a.remains_num == b.remains_num && a.sum_cut_length < b.sum_cut_length);
		}

		virtual ~criteria(void) {}
	};

	struct t_result {
		t_raskroy raskroy;
		t_part list;
		t_stat stat;
		unsigned ammount;

		t_result(void)
			: ammount(0)
		{
		}

		t_result(const t_result &orig)
			: raskroy(orig.raskroy), list(orig.list), ammount(orig.ammount)
		{
		}

        t_result& operator=(const t_result& cpy)
        {
        	raskroy = cpy.raskroy;
            list = cpy.list;
            stat = cpy.stat;
            ammount = cpy.ammount;
            return *this;
        }

        bool operator == (const t_result&);
        bool operator < (const t_result&);
	};

	typedef std::list<t_result> t_results_list;

	struct t_results : public t_results_list {
		scalar cut_thickness;
        bool operator==(const t_results&);
        bool operator<(const t_results&);
		//scalar torchevka;
	};

	class gilotine {
		class t_ammounts : public std::vector<unsigned> {
		public:
			t_ammounts& operator += (const t_ammounts &ammounts);
			t_ammounts& operator -= (const t_ammounts &ammounts);
			t_ammounts& operator *= (unsigned n);
			unsigned operator / (const t_ammounts&) const;
			t_ammounts operator * (unsigned n) const;
			t_ammounts operator - (const t_ammounts &ammounts) const;
            bool operator==(const t_ammounts&);
            bool operator<(const t_ammounts&);
		};

		class t_other_size
		{
		public:
			scalar size;
			unsigned n, offset;
			t_parts parts;
			t_other_size(void);
			void add_part(const t_part &part);
            bool operator==(const t_other_size&);
            bool operator<(const t_other_size&);
		};

		class t_other_sizes : public std::vector<t_other_size>
		{
			iterator min;
		public:
			iterator find(scalar size);
			void add_other_size(unsigned s, const t_part &part);
			void prepare(void);
			const_iterator watchMin(void) const;
            bool operator==(const t_other_sizes&);
            bool operator<(const t_other_sizes&);
		};

		struct t_size {scalar size; t_other_sizes other_sizes;bool operator==(const t_size&);bool operator<(const t_size&);};
		class t_sizes : public std::vector<t_size> {
		public:
			iterator find(scalar size);
			void add_size(unsigned s, const t_part &part);
            bool operator==(const t_sizes&);
            bool operator<(const t_sizes&);
		};

		t_ammounts remains;
		scalar perebor_remain;
		t_other_sizes::const_iterator perebor_i;
		t_other_sizes::const_iterator perebor_end;
		scalar recursive_perebor(scalar size, t_ammounts &rashod);
		bool perebor(const t_size &size, scalar other_size, t_stat &stat, t_raskroy &raskroy, t_ammounts &rashod);
		bool recursive(const t_list &list, t_stat &stat, unsigned s, t_raskroy &raskroy, t_ammounts &rashod);
		bool bylen_bywid(const t_list &list, t_stat &stat, t_raskroy &raskroy, t_ammounts &rashod);

		void make_materials_list(t_parts parts, t_parts lists);
		bool first;
		void add_part_to_sizes_list(unsigned s, const t_part &part);
		void make_sizes_lists_for_material(const t_material &);
		void remove_exosted_sizes(void);
		const criteria* pcriteria;
		t_stat statistic;
		t_sizes sizes[2];
		scalar minimum_size[2];
		t_materials materials;
		t_results results;
		unsigned recursion_depth;
		unsigned max_recursion_depth;
		t_factory factory;

	public:
		gilotine(void);
		void run(const t_parts &parts, const t_parts &lists, const t_factory &factory, const criteria &criteria);
		t_stat getStat(void) {return statistic;};
		t_results getResults(void) {return results;}
	};

	// inline implementation
	gilotine::t_other_size::t_other_size(void)
		: n(0)
	{
	}

	void gilotine::t_other_size::add_part(const t_part &part) {
		parts.push_back(part);
		n += part.ammount;
	};

	gilotine::t_other_sizes::iterator gilotine::t_other_sizes::find(scalar size)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->size == size)
				return i;
		return end();
	}

	void gilotine::t_other_sizes::add_other_size(unsigned s, const t_part &part)
	{
		t_other_size os;
		os.size = part.list.size[!s];
		os.add_part(part);
		push_back(os);
	}

	void gilotine::t_other_sizes::prepare(void)
	{
		min = begin();
		iterator i = begin();
		i++;
		for (; i != end(); i++)
			if (i->size < min->size)
				min = i;
	}

	gilotine::t_other_sizes::const_iterator gilotine::t_other_sizes::watchMin(void) const
	{
		assert(min);
		return min;
	}

	gilotine::t_sizes::iterator gilotine::t_sizes::find(scalar size)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->size == size)
				return i;
		return end();
	}

	void gilotine::t_sizes::add_size(unsigned s, const t_part &part)
	{
		t_size size;
		size.size = part.list.size[s];
		size.other_sizes.add_other_size(s, part);
		push_back(size);
	}

	gilotine::t_ammounts& gilotine::t_ammounts::operator += (const gilotine::t_ammounts &ammounts)
	{
		assert(size() == ammounts.size());
		iterator i1 = begin();
		const_iterator i2 = ammounts.begin();
		for (; i1 != end(); i1++, i2++)
			*i1 += *i2;
		return *this;
	}

	gilotine::t_ammounts& gilotine::t_ammounts::operator -= (const gilotine::t_ammounts &ammounts)
	{
		assert(size() == ammounts.size());
		iterator i1 = begin();
		const_iterator i2 = ammounts.begin();
		for (; i1 != end(); i1++, i2++)
			*i1 -= *i2;
		return *this;
	}

	gilotine::t_ammounts& gilotine::t_ammounts::operator *= (unsigned n)
	{
		for (iterator i = begin(); i != end(); i++)
			(*i) *= n;
		return *this;
	}

	gilotine::t_ammounts gilotine::t_ammounts::operator - (const gilotine::t_ammounts &a2) const
	{
		assert(size() == a2.size());
		t_ammounts res;
		res.resize(size());
		const_iterator i1 = begin();
		const_iterator i2 = a2.begin();
		iterator ri = res.begin();
		for (; i1 != end(); i1++, i2++, ri++)
		{
			(*ri) = (*i1) - (*i2);
		}
		return res;
	}

	gilotine::t_ammounts gilotine::t_ammounts::operator * (unsigned n) const
	{
		t_ammounts res;
		res.resize(size());
		const_iterator i = begin();
		iterator ri = res.begin();
		for (; i != end(); i++, ri++)
		{
			(*ri) = (*i) * n;
		}
		return res;
	}

	unsigned gilotine::t_ammounts::operator / (const gilotine::t_ammounts &a2) const
	{
		assert(size() == a2.size());
		unsigned mind;
		bool first = false;
		const_iterator i1 = begin();
		const_iterator i2 = a2.begin();
		for (; i1 != end(); i1++, i2++)
		{
			if (*i2 == 0)
				continue;

			unsigned d = (*i1)/(*i2);
			if (d == 0)
				return 0;
			if (first || d < mind)
			{
				first = false;
				mind = d;
			}
		}
		assert(!first);
		return mind;
	}

	// –екурсивный перебор
	// ѕараметры:
	//		[i] size - размер на котором нужно расположить детали
	//		[o] rashod - количество расположенных деталей
	scalar gilotine::recursive_perebor(scalar size, t_ammounts &rashod)
	{
		//if (i == perebor_other_sizes->end())
		//	return size;
		scalar register size1;
		//t_ammounts best_ammounts(ammounts.size());
		unsigned n;
		if (perebor_i != perebor_end)
		{
			n = 0;
			scalar best = size;
			size1 = size;
			t_ammounts rashod1;
			rashod1.resize(rashod.size());
			std::fill(rashod1.begin(), rashod1.end(), 0);
			while (size1 > factory.saw_thickness && n < remains[perebor_i->offset])
			{
				scalar remain;
				//if (size1 < perebor_minimum_size - factory.saw_thickness)
				//	remain = size1;
				//else
				//{
					perebor_i++;
					remain = recursive_perebor(size1, rashod1);
					perebor_i--;
				//}
				if (remain < best)
				{
					best = remain;
					//perebor_i->n = n;
					std::copy(rashod1.begin(), rashod1.end(), rashod.begin());
					rashod[perebor_i->offset] = n;
				}
				n++;
				size1 = size - (perebor_i->size+factory.saw_thickness)*n;
			}
			//ammounts = best_ammounts;
			return best;
		}
		else
		{
			n = unsigned((size+factory.saw_thickness)/(perebor_i->size+factory.saw_thickness));
			if (n > remains[perebor_i->offset])
				n = remains[perebor_i->offset];
			rashod[perebor_i->offset] = n;
			size1 = size - n*(perebor_i->size+factory.saw_thickness);
			return size1;
		}
	}

	// ѕеребор деталей одного базисного размера на другом размере с контролем остатков
	// ѕараметры:
	//		[i] size - базисный размер
	//		[i] other_size - перпендикул€рный размер
	//		[o] stat - статистика
	//		[o] raskroy - расположение деталей
	//		[o] rashod - расход деталей
	// ¬озвращает true если хот€ бы одна деталь установлена
	bool gilotine::perebor(const t_size &size, scalar other_size, t_stat &stat, t_raskroy &raskroy, t_ammounts &rashod)
	{
		if (other_size < size.other_sizes.watchMin()->size)
			return false;

		unsigned nums = 0;
		perebor_i = size.other_sizes.begin();
		perebor_end = size.other_sizes.end()-1;
		scalar remain = recursive_perebor(other_size, rashod);
		if (remain < other_size)
		{
			for (perebor_i = size.other_sizes.begin(); perebor_i != size.other_sizes.end(); perebor_i++)
				if (rashod[perebor_i->offset] > 0)
				{
					t_raskroy::t_detail detail;
					detail.size = perebor_i->size;
					detail.num = rashod[perebor_i->offset];
					raskroy.details.push_back(detail);
					nums += rashod[perebor_i->offset];
				}
			stat.sum_cut_length = size.size*(nums);
			stat.sum_remain = size.size*factory.saw_thickness;
			perebor_remain = remain;
			return true;
		}
		else
			return false;
	}

	// –екурсивный перебор всех делений листа по длине/ширине (s=0/1) с возможностью кратного расположени€
	// ѕараметры:
	//		[i] list - размеры листа
	//		[i/o] stat - статистика
	//		[i] s - выбор направлени€ раскро€ по длине/ширине s=0/1
	//		[o] raskroy - раскрой листа
	//		[o] rashod - расход деталей
	//
	bool gilotine::recursive(const t_list &list, t_stat &stat, unsigned s, t_raskroy &raskroy, t_ammounts &rashod)
	{
		recursion_depth++;
		if (recursion_depth > max_recursion_depth)
			goto nothing;
		if (list.size[s] < minimum_size[s])
			goto nothing;
		{bool first = true;
		t_stat best_stat;
		t_ammounts best_rashod;
		t_ammounts rashod1;
		rashod1.resize(remains.size());
		for (t_sizes::iterator i = sizes[s].begin(); i != sizes[s].end(); i++)
		{
			t_stat stat1;
			if (i->size > list.size[s])
				continue;
			else
			{
				t_raskroy raskroy1;
				std::fill(rashod1.begin(), rashod1.end(), 0);
				raskroy1.cut = i->size;
				raskroy1.s = s;
				stat1.sum_cut_length += list.size[!s];
				stat1.sum_remain += list.size[!s]*factory.saw_thickness;

				if (perebor(*i, list.size[!s], stat1, raskroy1, rashod1))
				{
					t_list list1;
					list1.size[s] = i->size;
					list1.size[!s] = perebor_remain;
					t_raskroy remain_raskroy;
					t_ammounts remain_rashod;
					remains -= rashod1;
					if (recursive(list1, stat1, !s, remain_raskroy, remain_rashod))
					{
						remains += rashod1;
						raskroy1.attachRemain(remain_raskroy);
						rashod1 += remain_rashod;
					}
					else
						remains += rashod1;
				}
				else
					continue;

				unsigned size_krat = (list.size[s] + factory.saw_thickness)/(i->size + factory.saw_thickness);
				unsigned kol_krat = remains/rashod1;
				if (size_krat > kol_krat)
					raskroy1.kratnostj = kol_krat;
				else
					raskroy1.kratnostj = size_krat;

				if (raskroy1.kratnostj == 0)						   
					assert(raskroy1.kratnostj);

				if (raskroy1.kratnostj > 1)
				{
					rashod1 *= raskroy1.kratnostj;
					stat1 *= raskroy1.kratnostj;
				}
				stat1 += stat;

				if (!first && pcriteria->compare(best_stat, stat1))	// already bad
					continue;

				if ((i->size + factory.saw_thickness)*raskroy1.kratnostj > list.size[s] - minimum_size[s])
				{
					stat1.sum_remain += (list.size[s] - (i->size + factory.saw_thickness)*raskroy1.kratnostj)*list.size[!s];
				}
				else
				{
					t_list list2(list);
					list2.size[s] = list.size[s] - (i->size + factory.saw_thickness)*raskroy1.kratnostj;
					t_raskroy recurse_raskroy;
					if (bylen_bywid(list2, stat1, recurse_raskroy, rashod1))
					raskroy1.attachRecurse(recurse_raskroy);
				}

				if (first || pcriteria->compare(stat1, best_stat))
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
			recursion_depth--;
			return true;
		}
		else
		{
			goto nothing;
		}}
		nothing:
		stat.sum_remain += list.size[0]*list.size[1];
		stat.remains_num++;
		recursion_depth--;
		return false;
	}

	// –аскрой листа по длине и по ширине, возвращает лучший выриант
	// ѕараметры:
	//		[i] list - размер листа
	//		[i/o] stat - статистика
	//		[o] raskroy - раскрой листа
	//		[i/o] rashod - расход деталей
	//
	bool gilotine::bylen_bywid(const t_list &list, t_stat &stat, t_raskroy &raskroy, t_ammounts &rashod)
	{
		if (recursion_depth+1 > max_recursion_depth)
			goto nothing;

		{
		t_stat stat1(stat), stat2(stat);
		t_ammounts rashod1, rashod2;
		t_raskroy raskroy1, raskroy2;

		remains -= rashod;
		bool rb1 = recursive(list, stat1, 0, raskroy1, rashod1);
		bool rb2 = false;
		if (rb1)
			rb2 = recursive(list, stat2, 1, raskroy2, rashod2);
		remains += rashod;
		if (rb1 && rb2)
		{
			if (pcriteria->compare(stat1, stat2))
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
			return true;
		}
		/*else if (rb1)
		{
			MessageBox(NULL, "hhh", 0, 0);
			stat = stat1;
			raskroy = raskroy1;
			return true;
		}
		else if (rb2)
		{
			MessageBox(NULL, "hhh", 0, 0);
			stat = stat2;
			raskroy = raskroy2;
			return true;
		}*/
		else
			goto nothing;
		}

	nothing:
		stat.sum_remain += list.size[0]*list.size[1];
		stat.remains_num++;
		return false;
	}

	void gilotine::make_materials_list(t_parts parts, t_parts lists)
	{
		while (!parts.empty())
		{
			t_parts::iterator i = parts.begin();
			t_material mtrl;
			mtrl.id = (*i).material_id;
			//t_parts::iterator j = parts.begin();
			while (i != parts.end())
			{
				if ((*i).material_id == mtrl.id)
				{
					mtrl.parts.push_back(*i);
					parts.erase(i);
					i = parts.begin();
				}
				else
					i++;
			}

			t_parts::iterator j = lists.begin();
			while (j != lists.end())
			{
				if ((*j).material_id == mtrl.id)
				{
					mtrl.lists.push_back(*j);
					lists.erase(j);
					j = lists.begin();
				}
				else
					j++;
			}
			materials.push_back(mtrl);
		}
	}

	void gilotine::add_part_to_sizes_list(unsigned s, const t_part &part)
	{
		t_sizes::iterator sizei = sizes[s].find(part.list.size[s]);
		if (sizei != sizes[s].end())
		{
			t_other_sizes::iterator other_sizei = sizei->other_sizes.find(part.list.size[!s]);
			if (other_sizei != sizei->other_sizes.end())
				other_sizei->add_part(part);
			else
				sizei->other_sizes.add_other_size(s, part);
		}
		else
		{
			sizes[s].add_size(s, part);
			if (first || minimum_size[s] > part.list.size[s])
			{
				first = false;
				minimum_size[s] = part.list.size[s];
			}
		}
	}

	void gilotine::make_sizes_lists_for_material(const t_material &material)
	{
		sizes[0].resize(0);
		sizes[1].resize(0);

		for (unsigned s = 0; s <= 1; s++)
		{
			first = true;
			for (t_parts::const_iterator parti = material.parts.begin(); parti != material.parts.end(); parti++)
			{
				add_part_to_sizes_list(s, *parti);
				if ((*parti).rotate/* || material.rotate*/)
				{
					t_part rotpart(*parti);
					rotpart.list.size[0] = (*parti).list.size[1];
					rotpart.list.size[1] = (*parti).list.size[0];
					add_part_to_sizes_list(s, rotpart);
				}
			}
			/*if (material.rotate)
				s++;	// skip */
		}

		for (t_sizes::iterator sizei0 = sizes[0].begin(); sizei0 != sizes[0].end(); sizei0++)
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
		}
	}

	void gilotine::remove_exosted_sizes(void)
	{
		for (unsigned s = 0; s <= 1; s++)
		{
			t_sizes::iterator sizei = sizes[s].begin();
			while (sizei != sizes[s].end())
			{
				t_other_sizes::iterator osi = sizei->other_sizes.begin();
				while (osi != sizei->other_sizes.end())
				{
					if (remains[osi->offset] == 0)
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


	gilotine::gilotine(void)
		: recursion_depth(0), max_recursion_depth(8)
	{
	}

	// Raskroy start
	void gilotine::run(const t_parts &parts, const t_parts &lists, const t_factory &factory, const criteria &criteria)
	{
		this->factory = factory;
		this->pcriteria = &criteria;
		make_materials_list(parts, lists);
		results.resize(0);
		results.cut_thickness = factory.saw_thickness;
		statistic.clear();
		for (t_materials::const_iterator mi = materials.begin(); !(mi.operator == (materials.end())); mi++)
		{
			make_sizes_lists_for_material(*mi);
			t_raskroy raskroy;
			t_result best_result;
			//best_result.torchevka = factory.
			t_ammounts rashod;
			rashod.resize(remains.size());
			while (1)
			{
				for (t_ammounts::const_iterator remainsi = remains.begin(); remainsi != remains.end(); remainsi++)
					if (*remainsi > 0)
						goto contine_raskroy;

				return;

				contine_raskroy:
				bool first = true;
				for (t_parts::const_iterator li = (*mi).lists.begin(); li != (*mi).lists.end(); li++)
				{
					t_stat stat;
					stat.clear();
					std::fill(rashod.begin(), rashod.end(), 0);
					if (bylen_bywid((*li).list, stat, raskroy, rashod))
						if (first || pcriteria->compare(stat, best_result.stat))
						{
							first = false;
							best_result.stat = stat;
							best_result.raskroy = raskroy;
							best_result.list = *li;
							best_result.ammount = remains/rashod;
							//if (best_result.ammount == 0)
							//	best_result.ammount = 1;
							if (best_result.ammount == 0)
								assert(best_result.ammount);
						}
				}
				if (first)
					throw runtime_error("Ќельз€ расположить детали.");
				else
					results.push_back(best_result);
				remains -= rashod*best_result.ammount;
				remove_exosted_sizes();
				statistic += best_result.stat;
			}
		}
	}

#if 0
#endif

}

#endif	// RASKROY_H_INCLUDED
