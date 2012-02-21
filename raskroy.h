#ifndef RASKROY_H_INCLUDED
#define RASKROY_H_INCLUDED

#include <iostream>
#include <list>
//#include <set>
#include <vector>
#include <memory>
#include <exception>
#include <assert.h>
#include <cstdlib>

// TODO: процент завершения
// TODO: есть глюк в тесте 1 на странице 1

namespace raskroy {

typedef double scalar;

struct t_rect {
	union
	{
		scalar size[2];
		struct {
			scalar length;
			scalar width;
		};
	};
	t_rect() {}
	t_rect(scalar len, scalar wid) : length(len), width(wid) {}
    //bool operator==(const t_rect& b) const {return size[0]==b.size[0] && size[1]==b.size[1];}
	scalar square() const {return length*width;}
};

struct err_part_invalid {
	const char* member;
	const char* value;
	err_part_invalid(const char* member, const char* value)
		: member(member), value(value)
	{
	}
};

struct t_part {
	t_rect rect;
	bool rotate;
	unsigned amount;

	t_part() {}
	t_part(scalar len, scalar wid, bool rotate=false, unsigned amount=0)
		: rect(len, wid), rotate(rotate), amount(amount) {}

	bool operator==(const t_part& b) const
	{
		return rect.size[0] == b.rect.size[0] && rect.size[1] == b.rect.size[1] &&
			rotate == b.rotate;
	}

	bool valid_rect_0(void) const
	{
		return rect.size[0] > 0 && rect.size[0] <= 100000;
	}

	bool valid_rect_1(void) const
	{
		return rect.size[1] > 0 && rect.size[1] <= 100000;
	}

	bool valid_amount(void) const
	{
		return amount <= 10000;
	}

#ifndef NDEBUG
	bool valid_rotate(void) const
	{
		return rotate == 0 || rotate == 1;
	}
#endif

	bool valid(void) const
	{
		return valid_rect_0() &&
			valid_rect_1() &&
#ifndef NDEBUG
			valid_rotate() &&
#endif
			valid_amount();
	}

	void validate(void) const
	{
		char buf[256];
		if (!valid_amount())
			throw err_part_invalid("amount", _ultoa(amount, buf, 12));
		if (!valid_rect_0())
			throw err_part_invalid("rect.size[0]", gcvt(rect.size[0], 0, buf));
		if (!valid_rect_1())
			throw err_part_invalid("rect.size[1]", gcvt(rect.size[1], 0, buf));
#ifndef NDEBUG
		if (!valid_rotate())
			throw err_part_invalid("rotate", rotate ? "true" : "false");
#endif
	}
};	// 16+4+4+4+4=32B

struct t_factory {
	scalar saw_thickness;
	scalar max_cut_length;

	t_factory(scalar saw_thickness=4, scalar max_cut_length=3000)
		: saw_thickness(saw_thickness), max_cut_length(max_cut_length)
	{
	}
};	// 16B

struct t_stat {
	scalar opilki;
	scalar useful_remain;
	scalar unuseful_remain;
	unsigned useful_num;
	scalar sum_cut_length;
	scalar sum_remain;
	unsigned remains_num;

	t_stat() {}

	t_stat(int zero) : opilki(0), useful_remain(0),	unuseful_remain(0), useful_num(0) {}

	t_stat& operator += (const t_stat& x)
	{
		opilki += x.opilki;
		useful_remain += x.useful_remain;
		unuseful_remain += x.unuseful_remain;
		useful_num += x.useful_num;
		return *this;
	}

	// меньше значит хуже
	friend inline bool operator < (const t_stat &a, const t_stat &b)
	{
		if (a.useful_remain + a.unuseful_remain + a.opilki > b.useful_remain + b.unuseful_remain + b.opilki)
			return true;
		if (a.useful_remain + a.unuseful_remain + a.opilki < b.useful_remain + b.unuseful_remain + b.opilki)
			return false;
		/*if (a.opilki + a.unuseful_remain > b.opilki + a.unuseful_remain)
			return true;
		if (a.opilki + a.unuseful_remain < b.opilki + a.unuseful_remain)
			return false;*/
		if (a.useful_num > b.useful_num)
			return true;
		//if (a.useful_num < b.useful_num)
		//	return false;
		return false;
	}

	friend inline bool operator > (const t_stat &a, const t_stat &b) {return (b < a);}
	
	void clear() {*this = t_stat();}
	void operator*=(unsigned factor)
	{
		opilki *= factor;
		useful_remain *= factor;
		useful_num *= factor;
		sum_cut_length *= factor;
		sum_remain *= factor;
		remains_num *= factor;
	}
};

struct t_parsed_part {
	scalar pos[2];	// положение относительно нижнего-левого угла
	t_rect rect;
};

struct t_parsed_cut {
	scalar pos[2];
	scalar length;
	unsigned s;	// пил по 0=длине или 1=ширине
	//unsigned force_8b_alignment;
};

class criteria {
public:
	virtual scalar __stdcall quality(const t_stat& s) const
	{	
		return -s.sum_remain - s.remains_num;
	}

	virtual __stdcall ~criteria(void) {}
	
	scalar compare(const t_stat * lhs, const t_stat * rhs) const
	{
		return quality(*rhs) - quality(*lhs);
	}
};

class monitor {
public:
	// вызывается по изменении прогресса
	virtual void __stdcall update_progress(unsigned)
	{
	}
};

	struct t_min_part {
		raskroy::t_rect rect;
		bool rotate;
		unsigned offset;
	};

	typedef std::vector<t_part> t_parts_vector;
	typedef std::list<t_part> t_parts_list;
	typedef t_parts_list t_parts;
	typedef std::vector<t_min_part> t_min_parts;

	struct t_raskroy {
		struct t_detail {scalar size; unsigned num;};
		typedef std::vector<t_detail> t_details;

		unsigned s, kratnostj;
		scalar cut;
		t_details details;

		t_raskroy()
			: premain(0), precurse(0) {}

		t_raskroy(const t_raskroy &orig)
			: s(orig.s), kratnostj(orig.kratnostj), cut(orig.cut), details(orig.details), premain(orig.premain), precurse(orig.precurse)
		{
			const_cast<t_raskroy*&>(orig.premain) = 0;
			const_cast<t_raskroy*&>(orig.precurse) = 0;
		}

		~t_raskroy() {
			delete premain;
			delete precurse;
		}

		inline t_raskroy& operator = (const t_raskroy &orig)
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
        
		inline void attachRemain(t_raskroy &remain) {
			if (premain)
				*premain = remain;
			else
				premain = new t_raskroy(remain);
		}

		inline void attachRecurse(t_raskroy &recurse) {
			if (precurse)
				*precurse = recurse;
			else
				precurse = new t_raskroy(recurse);
		}

		inline t_raskroy * watchRemain(void) const {
			return premain;
		}

		inline t_raskroy * watchRecurse(void) const {
			return precurse;
		}

	private:
		//t_result(const t_result &orig) {}
		mutable t_raskroy *premain;
		mutable t_raskroy *precurse;
	};

	struct t_result {
		t_raskroy raskroy;
		t_parts::iterator sheet;
		t_stat stat;
		unsigned amount;

		t_result(void)
			: amount(0)
		{
		}

		/*t_result(const t_result &orig)
			: raskroy(orig.raskroy), sheet(orig.sheet), amount(orig.amount)
		{
		}*/
	};

	//typedef std::list<t_result> t_results_list;

	//struct t_results : public t_results_list {
	//	scalar cut_thickness;
	//	t_stat stat;
		//scalar torchevka;
	//};

	class err_cannot_set_parts {
	public:
		err_cannot_set_parts()
		{
		}
	};

	class t_amounts : public std::vector<unsigned> {
	public:
		//t_amounts(void) {}
		//t_amounts(size_t size);
		t_amounts& operator += (const t_amounts &amounts);
		t_amounts& operator -= (const t_amounts &amounts);
		t_amounts& operator *= (unsigned n);
		unsigned operator / (const t_amounts&) const;
		t_amounts operator * (unsigned n) const;
		t_amounts operator - (const t_amounts &amounts) const;
	};

	class t_other_size
	{
	public:
		scalar size;
		t_min_parts parts;
		t_other_size(void);
		bool operator < (const t_other_size& b) const
		{
			return size < b.size;
		}
		unsigned num(const t_amounts &amounts) const;
		void make_rashod(t_amounts &rashod, unsigned num, const t_amounts &amounts) const;
	};

	class t_other_sizes : public std::vector<t_other_size>
	{
		iterator min;
	public:
		iterator find(scalar size);
		void add_other_size(unsigned s, const raskroy::t_min_part &part);
		void prepare(void);
		const_iterator watchMin(void) const;
	};

	struct t_size {
		scalar size;
		t_other_sizes other_sizes;
		bool operator < (const t_size& b) const
		{
			return size < b.size;
		}
	};
	class t_sizes : public std::vector<t_size> {
	public:
		iterator find(scalar size);
		void add_size(unsigned s, const raskroy::t_min_part &part);
	};

	// inline implementation
	inline t_other_size::t_other_size(void)
	{
	}

	inline unsigned t_other_size::num(const t_amounts& amounts) const
	{
		unsigned acc = 0;
		for (t_min_parts::const_iterator i = parts.begin(); i != parts.end(); i++)
			acc += amounts[i->offset];
		return acc;
	}

	inline void t_other_size::make_rashod(t_amounts& rashod, unsigned num, const t_amounts& amounts) const
	{
		for (t_min_parts::const_iterator i = parts.begin(); i != parts.end() && num > 0; i++)
		{
			unsigned amounti = amounts[i->offset];
			unsigned rashodi = num <= amounti ? num : amounti;
			rashod[i->offset] = rashodi;
			num -= rashodi;
		}
	}

	inline t_other_sizes::iterator t_other_sizes::find(scalar size)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->size == size)
				return i;
		return end();
	}

	inline void t_other_sizes::add_other_size(unsigned s, const t_min_part &part)
	{
		t_other_size os;
		os.size = part.rect.size[!s];
		os.parts.push_back(part);
		push_back(os);
	}

	inline void t_other_sizes::prepare(void)
	{
		min = begin();
		iterator i = begin();
		i++;
		for (; i != end(); i++)
			if (i->size < min->size)
				min = i;
	}

	inline t_other_sizes::const_iterator t_other_sizes::watchMin(void) const
	{
		return min;
	}

	inline t_sizes::iterator t_sizes::find(scalar size)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->size == size)
				return i;
		return end();
	}

	inline void t_sizes::add_size(unsigned s, const t_min_part &part)
	{
		t_size size;
		size.size = part.rect.size[s];
		size.other_sizes.add_other_size(s, part);
		push_back(size);
	}

	/*inline t_amounts::t_amounts(size_t size)
		: std::vector<unsigned>(size)
	{
	}*/

	inline t_amounts& t_amounts::operator += (const t_amounts &amounts)
	{
		assert(size() == amounts.size());
		iterator i1 = begin();
		const_iterator i2 = amounts.begin();
		for (; i1 != end(); i1++, i2++)
			*i1 += *i2;
		return *this;
	}

	inline t_amounts& t_amounts::operator -= (const t_amounts &amounts)
	{
		assert(size() == amounts.size());
		iterator i1 = begin();
		const_iterator i2 = amounts.begin();
		for (; i1 != end(); i1++, i2++)
			*i1 -= *i2;
		return *this;
	}

	inline t_amounts& t_amounts::operator *= (unsigned n)
	{
		for (iterator i = begin(); i != end(); i++)
			(*i) *= n;
		return *this;
	}

	inline t_amounts t_amounts::operator - (const t_amounts &a2) const
	{
		assert(size() == a2.size());
		t_amounts res;
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

	inline t_amounts t_amounts::operator * (unsigned n) const
	{
		t_amounts res;
		res.resize(size());
		const_iterator i = begin();
		iterator ri = res.begin();
		for (; i != end(); i++, ri++)
		{
			(*ri) = (*i) * n;
		}
		return res;
	}

	inline unsigned t_amounts::operator / (const t_amounts &a2) const
	{
		assert(size() == a2.size());
		unsigned mind;
		bool first = true;
		const_iterator i1 = begin();
		const_iterator i2 = a2.begin();
		for (; i1 != end(); i1++, i2++)
		{
			if (*i2 == 0)
				continue;

			unsigned d = (*i1)/(*i2);
#ifndef NVERBOSE
			std::cout << "d=" << d << std::endl;
			std::cout << "first=" << first << std::endl;
#endif
			if (d == 0)
				return 0;
			if (first || d < mind)
			{
				first = false;
				mind = d;
#ifndef NVERBOSE
				std::cout << "mind=" << mind << std::endl;
#endif
			}
		}
		assert(!first);
		return mind;
	}

	class Perebor {
		t_other_sizes::const_iterator i;
		t_other_sizes::const_iterator end;
		t_amounts &remains;

		scalar recursive(scalar size, t_amounts &rashod);

	public:
		scalar remain;
		scalar saw_thickness;

		Perebor(t_amounts &remains, scalar saw_thickness);
		bool make(const t_size &size, scalar other_size, t_stat&, t_raskroy&, t_amounts &rashod);
	};

	class Perebor2D {
		t_factory factory;
		t_amounts &remains;
		t_sizes *sizes;
		scalar *minimum_size;
		unsigned recursion_depth;
		Perebor perebor;
		monitor default_monitor;
		monitor *pmonitor;
		const criteria* pcriteria;

		bool recursive(const t_rect&, t_stat&, unsigned s, t_raskroy&, t_amounts &rashod);
		bool bylen_bywid(const t_rect&, t_stat&, t_raskroy&, t_amounts &rashod);

	public:
		unsigned max_recursion_depth;

		Perebor2D(t_sizes sizes[], scalar min_size[], t_amounts &remains, criteria&);
		void set_criteria(const criteria&);
		void set_monitor(monitor&);
		void set_factory(const t_factory&);

		bool make(const t_rect&, t_stat&, t_raskroy&, t_amounts &rashod);
	};

	typedef std::vector<t_parsed_part> t_parsed_parts;
	typedef std::vector<t_parsed_cut> t_parsed_cuts;

	struct t_parsed_result {
		t_parsed_parts parts;
		t_parsed_cuts cuts;
		t_stat stat;
		t_part sheet;
		unsigned amount;
	};

	class parser {
		t_parsed_result* poutresult;
		scalar saw_thickness, half_saw_thickness;

		scalar details(unsigned s, scalar pos[2], const t_rect&, const t_raskroy::t_details&);
		void recursive(scalar pos[2], const t_rect&, const t_raskroy&);
	public:
		parser(void) : poutresult(0), saw_thickness(0), half_saw_thickness(0) {}
		void parse(const t_result&, t_parsed_result&, scalar cut_thickness);
	};
	
	class gilotine {
		Perebor2D perebor_2d;

		criteria default_criteria;
		const criteria* pcriteria;

		t_amounts remains;

		t_sizes sizes[2];
		scalar minimum_size[2];

		t_parts sheets;

		t_stat common_stat;

		void remove_exosted_sizes(void);
		bool make_one_raskroy_result(t_result&);

	public:
		gilotine(void);

		void set_factory(const t_factory&);
		void set_recursion_max_depth(unsigned);
		void set_monitor(monitor&);
		void set_criteria(const criteria&);
		t_stat get_common_stat(void);

		bool first(const t_parts& parts, const t_parts& sheets, t_result&);
		bool next(t_result&);
	};
}

#endif	// RASKROY_H_INCLUDED
