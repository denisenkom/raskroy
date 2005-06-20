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

OtherSizes::iterator OtherSizes::Find(scalar size)
{
	for (iterator otherSize = begin(); otherSize != end(); otherSize++)
		if (otherSize->Value == size)
			return otherSize;
	return end();
}

void OtherSizes::Prepare(void)
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

OtherSize Sizes::MakeOtherSize(scalar os, unsigned amount, t_amounts &amounts, bool haveOffset, unsigned &offset)
{
	OtherSize otherSize;
	otherSize.Value = os;
	if (!haveOffset)
	{
		otherSize.Offset = offset = unsigned(amounts.size());
		amounts.push_back(amount);
	}
	else
		otherSize.Offset = offset;
	return otherSize;
}

void Sizes::AddSize(scalar s, scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset)
{
	iterator pSize = Find(s);
	if (pSize == end())
	{
		Size size;
		size.Value = s;
		size.OtherSizes.push_back(MakeOtherSize(os, amount, amounts, have_offset, offset));
		push_back(size);
	}
	else
	{
		OtherSizes::iterator pOtherSize = pSize->OtherSizes.Find(os);
		if (pOtherSize == pSize->OtherSizes.end())
			pSize->OtherSizes.push_back(MakeOtherSize(os, amount, amounts, have_offset, offset));
		else
			amounts[pOtherSize->Offset] += amount;
	}
}

// [io] sizes - ������ ������ �� 2� �� ������������������ ������� ��������, ������� ����������� ������
// [i] parts
// [o] ammounts - ������� ������ ��������� �������
void Sizes::MakeList(Sizes sizes[], const Parts &parts, t_amounts &amounts)
{
	amounts.clear();
	sizes[0].clear();
	sizes[1].clear();
	unsigned offset;
	for (Parts::const_iterator pPart = parts.begin(); pPart != parts.end(); pPart++)
	{
		const Part &part = *pPart;
		for (int s = 0; s != 2; s++)
		{
			sizes[s].AddSize(part.Rect.Size[s], part.Rect.Size[!s], part.Amount, amounts, s == 1, offset);
			if (part.Rotate && part.Rect.Size[s] != part.Rect.Size[!s])
				sizes[s].AddSize(part.Rect.Size[!s], part.Rect.Size[s], part.Amount, amounts, true, offset);
		}
	}
	// ���������� ��������
	for (int s = 0; s != 2; s++)
	{
		std::sort(sizes[s].begin(), sizes[s].end());
		for (Sizes::iterator pSize = sizes[s].begin(); pSize != sizes[s].end(); pSize++)
		{
			std::sort(pSize->OtherSizes.begin(), pSize->OtherSizes.end());
			// ��������� ��������� �� ����������� ������
			pSize->OtherSizes.Prepare();
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