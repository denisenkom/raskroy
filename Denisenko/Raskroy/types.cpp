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

OtherSize::OtherSize(scalar value, unsigned amount, Amounts &amounts, bool haveOffset, unsigned &offset)
: Value(value)
{
	if (haveOffset)
		Offset = offset;
	else
	{
		Offset = offset = unsigned(amounts.size());
		amounts.push_back(amount);
	}
}

OtherSizes::iterator OtherSizes::Find(scalar size)
{
	for (iterator otherSize = begin(); otherSize != end(); otherSize++)
		if (otherSize->Value == size)
			return otherSize;
	return end();
}

void OtherSizes::SetMin(void)
{
	iterator min = begin();
	for (iterator otherSize = begin(); otherSize != end(); otherSize++)
		if (otherSize->Value < min->Value)
			min = otherSize;
	Min = min;
}

Sizes::iterator Sizes::Find(scalar size)
{
	for (iterator pSize = begin(); pSize != end(); pSize++)
		if (pSize->Value == size)
			return pSize;
	return end();
}

void Sizes::AddSize(scalar size, scalar otherSize, unsigned amount, Amounts &amounts, bool haveOffset, unsigned &offset)
{
	iterator pSize = Find(size);
	if (pSize == end())
	{
		Size newSize;
		newSize.Value = size;
		newSize.OtherSizes.push_back(OtherSize(otherSize, amount, amounts, haveOffset, offset));
		push_back(newSize);
	}
	else
	{
		OtherSizes::iterator pOtherSize = pSize->OtherSizes.Find(otherSize);
		if (pOtherSize == pSize->OtherSizes.end())
			pSize->OtherSizes.push_back(OtherSize(otherSize, amount, amounts, haveOffset, offset));
		else
			amounts[pOtherSize->Offset] += amount;
	}
}

void Sizes::AddPart(Part &part, unsigned s, Amounts &amounts)
{
	AddSize(part.Rect.Size[s], part.Rect.Size[!s], part.Amount, amounts, s == 1, part.AmountOffset);
	if (part.Rotate && part.Rect.Size[s] != part.Rect.Size[!s])
		AddSize(part.Rect.Size[!s], part.Rect.Size[s], part.Amount, amounts, true, part.AmountOffset);
}

Amounts& Amounts::operator += (const Amounts &amounts)
{
	assert(size() == amounts.size());
	iterator i1 = begin();
	const_iterator i2 = amounts.begin();
	for (; i1 != end(); i1++, i2++)
		*i1 += *i2;
	return *this;
}

Amounts& Amounts::operator -= (const Amounts &amounts)
{
	assert(size() == amounts.size());
	iterator i1 = begin();
	const_iterator i2 = amounts.begin();
	for (; i1 != end(); i1++, i2++)
		*i1 -= *i2;
	return *this;
}

Amounts& Amounts::operator *= (unsigned n)
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

Amounts Amounts::operator - (const Amounts &a2) const
{
	assert(size() == a2.size());
	Amounts res;
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

Amounts Amounts::operator * (unsigned n) const
{
	if (n == 1)
		return *this;
	Amounts res;
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

unsigned Amounts::operator / (const Amounts &a2) const
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