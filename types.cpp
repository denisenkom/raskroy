#include "stdafx.h"
#include "types.h"

namespace Denisenko {
namespace Raskroy {

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
	Amounts res(size());
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
	Amounts res(size());
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
	assert(size() != 0);
	unsigned mind = 0;
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
