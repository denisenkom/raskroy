#ifndef RASKROY_TYPES_HPP_INCLUDED
#define RASKROY_TYPES_HPP_INCLUDED

namespace raskroy {

	typedef double scalar;

	struct t_rect {
		scalar size[2];
        bool operator==(t_rect& b) {return size[0]==b.size[0] && size[1]==b.size[1]}
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
		t_factory(void) {}
		t_factory(scalar saw_thickness, scalar max_cut_length)
			: saw_thickness(saw_thickness), max_cut_length(max_cut_length)
		{
		}
	};	// 16B

	struct t_stat {
		scalar sum_cut_length;
		scalar sum_remain;
		unsigned remains_num;
		unsigned force_8b_alignment;

		t_stat() : sum_cut_length(0), sum_remain(0) {}
		t_stat(scalar sum_cut_length, scalar sum_remain)
			: sum_cut_length(sum_cut_length), sum_remain(sum_remain) {}

		t_stat& operator += (const t_stat& stat) {
			sum_cut_length += stat.sum_cut_length;
			sum_remain += stat.sum_remain;
			remains_num += stat.remains_num;
			return *this;
		}

		t_stat& operator *= (unsigned k) {
			sum_cut_length *= k;
			sum_remain *= k;
			remains_num *= k;
			return *this;
		}

		void clear(void) {
			sum_cut_length = 0;
			sum_remain = 0;
			remains_num = 0;
		}
	};	// 24B

	struct t_parsed_part {
		scalar pos[2];	// положение относительно нижнего-левого угла
		raskroy::t_rect rect;
	};

	struct t_parsed_cut {
		scalar pos[2];
		scalar length;
		unsigned s;	// пил по 0=длине или 1=ширине
		unsigned force_8b_alignment;
	};

	class criteria {
	public:
		// return true if a better than b
		virtual bool __stdcall compare(const t_stat* pa, const t_stat* pb) const
		{
			return (pa->sum_remain < pb->sum_remain
				|| pa->sum_remain == pb->sum_remain && pa->remains_num < pb->remains_num
				|| pa->sum_remain == pb->sum_remain && pa->remains_num == pb->remains_num && pa->sum_cut_length < pb->sum_cut_length);
		}

		virtual __stdcall ~criteria(void) {}
	};

	class monitor {
	public:
		// вызывается по изменении прогресса
		virtual void __stdcall update_progress(unsigned)
		{
		}
	};

}

#endif	// RASKROY_TYPES_HPP_INCLUDED