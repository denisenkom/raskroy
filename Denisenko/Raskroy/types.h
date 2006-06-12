#ifndef TypesH
#define TypesH

#include <list>

namespace Denisenko {
namespace Raskroy {

typedef __int64 scalar;

struct Rect {
	scalar Size[2];

	Rect() {}
	Rect(scalar size0, scalar size1)
	{
		Size[0] = size0;
		Size[1] = size1;
	}
};

struct Part {
	Rect Rect;
	bool Rotate;
	unsigned Amount;
	unsigned AmountOffset;
	int Tag;

	Part() {}
	Part(scalar size0, scalar size1, bool rotate = false, unsigned amount = 0)
		: Rect(size0, size1), Rotate(rotate), Amount(amount) {}

	bool operator == (const Part& b) const
	{
		return(Rect.Size[0] == b.Rect.Size[0] && Rect.Size[1] == b.Rect.Size[1] ||
			(Rotate || b.Rotate) && Rect.Size[1] == b.Rect.Size[0] && Rect.Size[0] == b.Rect.Size[1])
	}
};	// 16+4+4+4+4=32B

typedef std::list<Part> Parts;

struct Stat {
	double Opilki;
	double UsefulRemain;
	double UnusefulRemain;
	unsigned UsefulNum;

	//Stat() {}

	void MakeZero()
	{
		Opilki = 0.0;
		UsefulRemain = 0.0;
		UnusefulRemain = 0.0;
		UsefulNum = 0;
	}

	//Stat(int zero) : Opilki(0.0), UsefulRemain(0.0), UnusefulRemain(0.0), UsefulNum(0) {}

	Stat& operator += (const Stat& x)
	{
		Opilki += x.Opilki;
		UsefulRemain += x.UsefulRemain;
		UnusefulRemain += x.UnusefulRemain;
		UsefulNum += x.UsefulNum;
		return *this;
	}

	// меньше значит хуже
	bool operator < (const Stat &b)
	{
		if (UsefulRemain + UnusefulRemain + Opilki > b.UsefulRemain + b.UnusefulRemain + b.Opilki)
			return true;
		if (UsefulRemain + UnusefulRemain + Opilki < b.UsefulRemain + b.UnusefulRemain + b.Opilki)
			return false;
		//if (Opilki + UnusefulRemain > b.Opilki + b.UnusefulRemain)
		//	return true;
		//if (Opilki + UnusefulRemain < b.Opilki + b.UnusefulRemain)
		//	return false;
		if (UsefulNum > b.UsefulNum)
			return true;
		//if (UsefulNum < b.UsefulNum)
		//	return false;
		return false;
	}

	void AddScrap(const Rect& rect)
	{
		double square = (double)rect.Size[0] * (double)rect.Size[1];
		if(IsUseful(rect))
		{
			UsefulRemain += square;
			UsefulNum += 1;
		}
		else
		{
			UnusefulRemain += square;
		}
	}

	static const scalar MIN_USEFUL_SIZE1 = 70;
	static const scalar MIN_USEFUL_SIZE2 = 200-34;

	static bool IsUseful(const Rect& rect)
	{
		return (rect.Size[0] >= MIN_USEFUL_SIZE1 && rect.Size[1] >= MIN_USEFUL_SIZE2)
			|| (rect.Size[1] >= MIN_USEFUL_SIZE1 && rect.Size[0] >= MIN_USEFUL_SIZE2);
	}

	bool IsEqual(const Stat& stat, double precise = 1000000.0) const
	{
		return (fabs(this->Opilki - stat.Opilki) < precise &&
			fabs(this->UnusefulRemain - stat.UnusefulRemain) < precise &&
			fabs(this->UsefulRemain - stat.UsefulRemain) < precise &&
			this->UsefulNum == stat.UsefulNum);
	}
};

class Amounts : public std::vector<unsigned> {
public:
	Amounts& operator += (const Amounts &amounts);
	Amounts& operator -= (const Amounts &amounts);
	Amounts& operator *= (unsigned n);
	unsigned operator / (const Amounts&) const;
	Amounts operator * (unsigned n) const;
	Amounts operator - (const Amounts &amounts) const;
	Amounts operator + (const Amounts &b) const {Amounts res(*this); return (res += b);};

	Amounts(size_t size)
		: std::vector<unsigned>(size)
	{
	}

	bool IsAllZeros() { for(const_iterator i = begin(); i != end(); i++) if(*i > 0) return false; return true; }
};

class OtherSize
{
public:
	scalar Value;
	unsigned Offset;

	OtherSize(void) {};
	OtherSize(scalar value, unsigned amount, Amounts &amounts, bool haveOffset, unsigned &offset);
	bool operator < (const OtherSize& b) const {return Value < b.Value;}
};

class OtherSizes : public std::vector<OtherSize>
{
public:
	iterator Min;

	iterator Find(scalar size);
	void SetMin(void);
};

struct Size {
	scalar Value;
	OtherSizes OtherSizes;
	bool operator < (const Size& b) const {return Value < b.Value;}
};

class Sizes : public std::vector<Size> {
	iterator Find(scalar size);
	void AddSize(scalar s, scalar otherSize, unsigned amount, Amounts &amounts, bool haveOffset, unsigned &offset);
public:
	void AddPart(Part &part, unsigned s, Amounts &amounts);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // TypesH