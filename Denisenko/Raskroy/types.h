#ifndef TypesH
#define TypesH

#include <list>

namespace Denisenko {
namespace Raskroy {

typedef double scalar;

struct Rect {
	union
	{
		scalar Size[2];
		struct {
			scalar Length;
			scalar Width;
		};
	};
	Rect() {}
	Rect(scalar length, scalar width) : Length(length), Width(width) {}
	scalar Square() const {return Length * Width;}
};

struct Part {
	Rect Rect;
	bool Rotate;
	unsigned Amount;

	Part() {}
	Part(scalar length, scalar width, bool rotate = false, unsigned amount = 0)
		: Rect(length, width), Rotate(rotate), Amount(amount) {}

	bool operator == (const Part& b) const
	{
		return Rect.Length == b.Rect.Length && Rect.Width == b.Rect.Width &&
			Rotate == b.Rotate;
	}
};	// 16+4+4+4+4=32B

struct t_stat {
	scalar opilki;
	scalar useful_remain;
	scalar unuseful_remain;
	unsigned useful_num;

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
	bool operator < (const t_stat &b)
	{
		if (useful_remain + unuseful_remain + opilki > b.useful_remain + b.unuseful_remain + b.opilki)
			return true;
		if (useful_remain + unuseful_remain + opilki < b.useful_remain + b.unuseful_remain + b.opilki)
			return false;
		/*if (opilki + unuseful_remain > b.opilki + b.unuseful_remain)
			return true;
		if (opilki + unuseful_remain < b.opilki + b.unuseful_remain)
			return false;*/
		if (useful_num > b.useful_num)
			return true;
		//if (useful_num < b.useful_num)
		//	return false;
		return false;
	}
};

typedef std::vector<Part> t_parts_vector;
typedef std::list<Part> t_parts_list;
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

	~t_raskroy() {
		delete premain;
		delete precurse;
	}

	void set(int s, unsigned kratnostj, scalar cut, t_details &details, t_raskroy *premain, t_raskroy *precurse);
	t_raskroy& operator = (const t_raskroy &orig);
	void attachRemain(t_raskroy &remain);
	void attachRecurse(t_raskroy &recurse);
	t_raskroy * watchRemain(void) const {return premain;}
	t_raskroy * watchRecurse(void) const {return precurse;}

private:
	mutable t_raskroy *premain;
	mutable t_raskroy *precurse;
};

struct t_result {
	t_raskroy raskroy;
	t_parts::iterator sheet;
	t_stat stat;
	unsigned amount;

	t_result(void) : amount(0) {}
};

class t_amounts : public std::vector<unsigned> {
public:
	t_amounts& operator += (const t_amounts &amounts);
	t_amounts& operator -= (const t_amounts &amounts);
	t_amounts& operator *= (unsigned n);
	unsigned operator / (const t_amounts&) const;
	t_amounts operator * (unsigned n) const;
	t_amounts operator - (const t_amounts &amounts) const;
	t_amounts operator + (const t_amounts &b) const {t_amounts res(*this); return (res += b);};
};

class t_other_size
{
public:
	scalar size;
	unsigned offset;

	t_other_size(void) {};
	bool operator < (const t_other_size& b) const {return size < b.size;}
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
	bool operator < (const t_size& b) const {return size < b.size;}
};

class t_sizes : public std::vector<t_size> {
	iterator find(scalar size);
	t_other_size make_other_size(scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset);
	void add_size(scalar s, scalar os, unsigned amount, t_amounts &amounts, bool have_offset, unsigned &offset);
public:
	static void make_list(t_sizes sizes[], const t_parts &parts, t_amounts &amounts);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // TypesH