#ifndef RASKROY_H_INCLUDED
#define RASKROY_H_INCLUDED

#include <list>
#include <memory>
//#include <cassert>

namespace raskroy {

	typedef float scalar;
	typedef struct {scalar size[2];} t_list;
	typedef struct {unsigned id; t_list list; bool rotate;
		unsigned ammount; unsigned material_id;} t_part;
	typedef std::list<t_part> t_parts_list;
	typedef struct {unsigned id; t_parts_list parts; t_parts_list lists;} t_material;
	typedef std::list<t_material> t_materials_list;
	typedef struct {scalar size; unsigned n; t_part *part;} t_other_size;
	typedef std::list<t_other_size> t_other_sizes_list;
	typedef struct {scalar size; t_other_sizes_list other_sizes;} t_size;
	typedef std::list<t_size> t_sizes_list;

	//typedef std::vector<unsigned n> t_other_sizes_result_list;
	//typedef std::list<struct {unsigned size_i, unsigned s, t_other_sizes_result_list other_sizes}>
	//typedef struct s_result {bool bylen; std::list<t_cut> cuts, std::list<s_result>} t_result;

	typedef struct {scalar saw_thickness;} t_factory;
	struct t_stat {
		scalar sum_cut_length;
		scalar sum_remain;
		t_stat() : sum_cut_length(0), sum_remain(0) {}
		t_stat& operator += (const t_stat& stat) {
			sum_cut_length += stat.sum_cut_length;
			sum_remain += stat.sum_remain;
			return *this;
		}
	};

	class criteria {
	public:
		// return true if a better than b
		virtual bool compare(t_stat a, t_stat b)
		{
			if (a.sum_remain < b.sum_remain)
				return true;
			if (a.sum_cut_length < b.sum_cut_length)
				return true;
			return false;
		}

		virtual ~criteria(void) {}
	};
	
	class gilotine {
		t_other_sizes_list* pperebor_sizes;
		t_other_sizes_list::iterator perebor_i;
		scalar perebor(scalar size);		
		void recursive(const t_list &list, t_stat &stat, unsigned s);
		void bylen_bywid(const t_list &list, t_stat &stat);

		void make_materials_list(void);		
		void make_sizes_lists_for_material(const t_material &);
		std::auto_ptr<criteria> pcriteria;
		t_stat statistic;
		t_sizes_list sizes[2];
		struct {scalar size; scalar other_size;} minimum_size[2];
		t_materials_list materials;
	public:
		t_factory factory;
		t_parts_list parts;
		t_parts_list lists;

		gilotine(const t_parts_list &parts, const t_parts_list &lists, const t_factory &factory/*, criteria *pcriteria*/);
		void run(void);
		t_stat getStat(void) {return statistic;};
	};
}

#endif	// RASKROY_H_INCLUDED
