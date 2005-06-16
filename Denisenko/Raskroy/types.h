#ifndef TypesH
#define TypesH

namespace Denisenko {
namespace Raskroy {

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
			throw err_part_invalid("amount", ultoa(amount, buf, 12));
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

/*class criteria {
public:
	virtual scalar __stdcall quality(const t_stat& s) const
	{	
		return -s.sum_remain - s.remains_num;
	}

	virtual __stdcall ~criteria(void) {}
};*/

class monitor {
public:
	// вызывается по изменении прогресса
	virtual void __stdcall update_progress(unsigned)
	{
	}
};

} // namespace Denisenko
} // namespace Raskroy

#endif // TypesH