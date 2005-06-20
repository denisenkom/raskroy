#include "stdafx.h"
#include "types.h"

namespace Denisenko {
namespace Raskroy {

void t_raskroy::set(int s,
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

t_raskroy& t_raskroy::operator = (const t_raskroy &orig)
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

void t_raskroy::attachRemain(t_raskroy &remain) {
	if (premain)
		*premain = remain;
	else
		premain = new t_raskroy(remain);
}

void t_raskroy::attachRecurse(t_raskroy &recurse) {
	if (precurse)
		*precurse = recurse;
	else
		precurse = new t_raskroy(recurse);
}

t_other_sizes::iterator t_other_sizes::find(scalar size)
{
	for (iterator i = begin(); i != end(); i++)
		if (i->size == size)
			return i;
	return end();
}

void t_other_sizes::prepare(void)
{
	min = begin();
	iterator i = begin();
	i++;
	for (; i != end(); i++)
		if (i->size < min->size)
			min = i;
}

t_sizes::iterator t_sizes::find(scalar size)
{
	for (iterator i = begin(); i != end(); i++)
		if (i->size == size)
			return i;
	return end();
}

t_other_size t_sizes::make_other_size(scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset)
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

void t_sizes::add_size(scalar s, scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset)
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
void t_sizes::make_list(t_sizes sizes[], const Parts &parts, t_amounts &amounts)
{
	amounts.clear();
	sizes[0].clear();
	sizes[1].clear();
	unsigned offset;
	for (Parts::const_iterator i = parts.begin(); i != parts.end(); i++)
	{
		const Part &part = *i;
		for (int s = 0; s != 2; s++)
		{
			sizes[s].add_size(part.Rect.Size[s], part.Rect.Size[!s], part.Amount, amounts, s == 1, offset);
			if (part.Rotate && part.Rect.Size[s] != part.Rect.Size[!s])
				sizes[s].add_size(part.Rect.Size[!s], part.Rect.Size[s], part.Amount, amounts, true, offset);
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

t_amounts& t_amounts::operator += (const t_amounts &amounts)
{
	assert(size() == amounts.size());
	iterator i1 = begin();
	const_iterator i2 = amounts.begin();
	for (; i1 != end(); i1++, i2++)
		*i1 += *i2;
	return *this;
}

t_amounts& t_amounts::operator -= (const t_amounts &amounts)
{
	assert(size() == amounts.size());
	iterator i1 = begin();
	const_iterator i2 = amounts.begin();
	for (; i1 != end(); i1++, i2++)
		*i1 -= *i2;
	return *this;
}

t_amounts& t_amounts::operator *= (unsigned n)
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

t_amounts t_amounts::operator - (const t_amounts &a2) const
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

t_amounts t_amounts::operator * (unsigned n) const
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

unsigned t_amounts::operator / (const t_amounts &a2) const
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