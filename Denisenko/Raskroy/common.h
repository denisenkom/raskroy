#ifndef CommonH
#define CommonH

#include <stdlib.h>
#include <assert.h>
#include <list>
#include <vector>
#include <algorithm>
#include "types.hpp"

namespace Denisenko {
namespace Raskroy {

/*struct t_min_part {
	raskroy::t_rect rect;
	bool rotate;
	unsigned amount;
};
typedef std::vector<t_min_part> t_min_parts;*/

typedef std::vector<t_part> t_parts_vector;
typedef std::list<t_part> t_parts_list;
typedef t_parts_list t_parts;

struct t_raskroy {
	struct t_detail {scalar size; unsigned num;};
	typedef std::vector<t_detail> t_details;

	unsigned s;
	unsigned kratnostj;
	scalar cut;
	t_details details;

	t_raskroy() : premain(0), precurse(0) {}

	t_raskroy(const t_raskroy &orig)
		: s(orig.s),
		kratnostj(orig.kratnostj),
		cut(orig.cut),
		details(orig.details),
		premain(orig.premain),
		precurse(orig.precurse)
	{
		orig.premain = 0;
		orig.precurse = 0;
	}

	void set(int s,
		unsigned kratnostj,
		scalar cut,
		t_details &details,
		t_raskroy *premain,
		t_raskroy *precurse)
	{
		this->s = s;
		this->kratnostj = kratnostj;
		this->cut = cut;
		this->details = details;
		delete this->premain;
		this->premain = premain ? new t_raskroy(*premain) : 0;
		delete this->precurse;
		this->precurse = precurse ? new t_raskroy(*precurse) : 0;
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

inline t_amounts operator + (const t_amounts &a, const t_amounts &b)
{
	t_amounts res(a);
	return (res += b);
}

class t_other_size
{
public:
	scalar size;
	unsigned offset;

	t_other_size(void);
	bool operator < (const t_other_size& b) const
	{
		return size < b.size;
	}
};

class t_other_sizes : public std::vector<t_other_size>
{
public:
	iterator min;

	iterator find(scalar size);
	void prepare(void);
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
	iterator find(scalar size);
	t_other_size make_other_size(scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset);
	void add_size(scalar s, scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset);
public:
	static void make_list(t_sizes sizes[], const t_parts &parts, t_amounts &amounts);
};

class err_cannot_set_parts {
public:
	t_parts &sheets;
	t_sizes *sizes;
	t_amounts &remains;

	err_cannot_set_parts(t_parts &sheets,
		t_sizes sizes[],
		t_amounts &remains)
		: sheets(sheets),
			sizes(sizes),
			remains(remains)
	{
	}
};

// inline implementation
inline t_other_size::t_other_size(void)
{
}

/*inline unsigned t_other_size::num(const t_amounts& amounts) const
{
	unsigned acc = 0;
	for (t_min_parts::const_iterator i = parts.begin(); i != parts.end(); i++)
		acc += amounts[i->offset];
	return acc;
}*/

// [i] num
// [i] amounts
// [o] rashod 
/*inline void t_other_size::make_rashod(t_amounts& rashod, unsigned num, const t_amounts& amounts) const
{
	rashod.resize(remains.size());
	std::fill(rashod.begin(), rashod.end(), 0);
	for (t_min_parts::const_iterator i = parts.begin(); i != parts.end() && num > 0; i++)
	{
		unsigned amount_for_part = amounts[i->offset];
		unsigned rashod_for_part = num <= amount_for_part ? num : amount_for_part;
		rashod[i->offset] = rashod_for_part;
		num -= rashod_for_part;
	}
}*/

inline t_other_sizes::iterator t_other_sizes::find(scalar size)
{
	for (iterator i = begin(); i != end(); i++)
		if (i->size == size)
			return i;
	return end();
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

inline t_sizes::iterator t_sizes::find(scalar size)
{
	for (iterator i = begin(); i != end(); i++)
		if (i->size == size)
			return i;
	return end();
}

inline t_other_size t_sizes::make_other_size(scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset)
{
	t_other_size other_size;
	other_size.size = os;
	if (!have_offset)
	{
		other_size.offset = offset = unsigned(amounts.size());
		amounts.push_back(amount);
	}
	else
		other_size.offset = offset;
	return other_size;
}

inline void t_sizes::add_size(scalar s, scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset)
{
	iterator i = find(s);
	if (i == end())
	{
		t_size size;
		size.size = s;
		size.other_sizes.push_back(make_other_size(os, amount, amounts, have_offset, offset));
		push_back(size);
	}
	else
	{
		t_other_sizes::iterator j = i->other_sizes.find(os);
		if (j == i->other_sizes.end())
			i->other_sizes.push_back(make_other_size(os, amount, amounts, have_offset, offset));
		else
			amounts[j->offset] += amount;
	}
}

// [io] sizes - входит массив из 2х не инициализированных списков размеров, выходят заполненные списки
// [i] parts
// [o] ammounts - выходит массив количеств деталей
inline void t_sizes::make_list(t_sizes sizes[], const t_parts &parts, t_amounts &amounts)
{
	amounts.clear();
	sizes[0].clear();
	sizes[1].clear();
	unsigned offset;
	for (t_parts::const_iterator i = parts.begin(); i != parts.end(); i++)
	{
		const t_part &part = *i;
		for (int s = 0; s != 2; s++)
		{
			sizes[s].add_size(part.rect.size[s], part.rect.size[!s], part.amount, amounts, s == 1, offset);
			if (part.rotate && part.rect.size[s] != part.rect.size[!s])
				sizes[s].add_size(part.rect.size[!s], part.rect.size[s], part.amount, amounts, true, offset);
		}
	}
	// Сортировка размеров
	for (int s = 0; s != 2; s++)
	{
		std::sort(sizes[s].begin(), sizes[s].end());
		for (t_sizes::iterator i = sizes[s].begin(); i != sizes[s].end(); i++)
		{
			std::sort(i->other_sizes.begin(), i->other_sizes.end());
			// установка указателя на минимальный размер
			i->other_sizes.prepare();
		}
	}
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
	if (n == 1)
		return *this;
	if (n == 0)
	{
		std::fill(begin(), end(), 0);
		return *this;
	}
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
	if (n == 1)
		return *this;
	t_amounts res;
	res.resize(size());
	if (n == 0)
	{
		std::fill(res.begin(), res.end(), 0);
		return res;
	}
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

} // Raskroy
} // Denisenko

#endif	// CommonH