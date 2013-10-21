#include "stdafx.h"
#include "types.h"

namespace Denisenko {
namespace Raskroy {

void PartKey::normalize() {
    if (can_rotate) {
        if (rect.Size[0] < rect.Size[1]) {
            std::swap(rect.Size[0], rect.Size[1]);
        }
    }
}


bool PartKey::operator <(const PartKey & rhs) const {
    if (rect.Size[0] < rhs.rect.Size[0])
        return true;
    else if (rect.Size[0] > rhs.rect.Size[0])
        return false;
    if (rect.Size[1] < rhs.rect.Size[1])
        return true;
    else if (rect.Size[1] > rhs.rect.Size[1])
        return false;
    if (!can_rotate && rhs.can_rotate)
        return true;
    else
        return false;
}


OtherSize::OtherSize(scalar value)
: Value(value)
{
}


void OtherSize::set_consumption(unsigned amount, const Amounts & remains, Amounts & consumptions) const {
    for (auto parti = parts.begin();
         parti != parts.end();
         parti++)
    {
        if (amount == 0)
            break;
        auto index = (*parti)->AmountOffset;
        auto consume = std::min(amount, remains[index]);
        consumptions[index] = consume;
        amount -= consume;
    }
    assert(amount == 0);
}


OtherSizes::iterator OtherSizes::Find(scalar size)
{
	for (auto otherSize = begin(); otherSize != end(); otherSize++)
		if (otherSize->Value == size)
			return otherSize;
	return end();
}

void OtherSizes::SetMin(void)
{
	auto min = begin();
	for (auto otherSize = begin(); otherSize != end(); otherSize++)
		if (otherSize->Value < min->Value)
			min = otherSize;
	Min = min;
}

Sizes::iterator Sizes::Find(scalar size)
{
	for (auto pSize = begin(); pSize != end(); pSize++)
		if (pSize->Value == size)
			return pSize;
	return end();
}

void Sizes::AddSize(scalar size, scalar otherSize, Part * part)
{
    auto pSize = Find(size);
    if (pSize == end())
    {
        Size newSize;
        newSize.Value = size;
        OtherSize other_size(otherSize);
        other_size.parts.push_back(part);
        newSize.other_sizes.push_back(other_size);
        push_back(newSize);
    }
    else
    {
        auto pOtherSize = pSize->other_sizes.Find(otherSize);
        if (pOtherSize == pSize->other_sizes.end()) {
            OtherSize other_size(otherSize);
            other_size.parts.push_back(part);
            pSize->other_sizes.push_back(other_size);
        } else {
            pOtherSize->parts.push_back(part);
        }
    }
}

void Sizes::AddPart(Part &part, unsigned s)
{
    if (part.Amount <= 0)
        return;
	AddSize(part.rect.Size[s], part.rect.Size[!s], &part);
	if (part.Rotate && part.rect.Size[s] != part.rect.Size[!s])
		AddSize(part.rect.Size[!s], part.rect.Size[s], &part);
}

Amounts& Amounts::operator += (const Amounts &amounts)
{
	assert(size() == amounts.size());
	auto i1 = begin();
	auto i2 = amounts.begin();
	for (; i1 != end(); i1++, i2++)
		*i1 += *i2;
	return *this;
}

Amounts& Amounts::operator -= (const Amounts &amounts)
{
	assert(size() == amounts.size());
	auto i1 = begin();
	auto i2 = amounts.begin();
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
	for (auto i = begin(); i != end(); i++)
		(*i) *= n;
	return *this;
}

Amounts Amounts::operator - (const Amounts &a2) const
{
	assert(size() == a2.size());
	auto res = Amounts(size());
	auto i1 = begin();
	auto i2 = a2.begin();
	auto ri = res.begin();
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
	auto res = Amounts(size());
	if (n == 0)
	{
		std::fill(res.begin(), res.end(), 0);
		return res;
	}
	auto i = begin();
	auto ri = res.begin();
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
	auto mind = 0u;
	auto first = true;
	auto i1 = begin();
	auto i2 = a2.begin();
	for (; i1 != end(); i1++, i2++)
	{
		if (*i2 == 0)
			continue;

		auto d = (*i1)/(*i2);
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
