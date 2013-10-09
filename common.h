namespace raskroy {

	struct t_min_part {
		raskroy::t_rect rect;
		bool rotate;
		unsigned offset;
	};

	typedef std::vector<t_part> t_parts_vector;
	typedef std::list<t_part> t_parts_list;
	typedef t_parts_list t_parts;
	typedef std::vector<t_min_part> t_min_parts;

	struct t_raskroy {
		struct t_detail {scalar size; unsigned num;};
		typedef std::vector<t_detail> t_details;

		unsigned s, kratnostj;
		scalar cut;
		t_details details;

		t_raskroy()
			: premain(0), precurse(0) {}

		t_raskroy(const t_raskroy &orig)
			: s(orig.s), kratnostj(orig.kratnostj), cut(orig.cut), details(orig.details), premain(orig.premain), precurse(orig.precurse)
		{
			const_cast<t_raskroy*>(orig.premain) = 0;
			const_cast<t_raskroy*>(orig.precurse) = 0;
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

	class err_cannot_set_parts {
	public:
		err_cannot_set_parts()
		{
		}
	};

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

	class t_other_size
	{
	public:
		scalar size;
		t_min_parts parts;
		t_other_size(void);
		bool operator < (const t_other_size& b) const
		{
			return size < b.size;
		}
		unsigned num(const t_amounts &amounts) const;
		void make_rashod(t_amounts &rashod, unsigned num, const t_amounts &amounts) const;
	};

	class t_other_sizes : public std::vector<t_other_size>
	{
		iterator min;
	public:
		iterator find(scalar size);
		void add_other_size(unsigned s, const raskroy::t_min_part &part);
		void prepare(void);
		const_iterator watchMin(void) const;
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
	public:
		iterator find(scalar size);
		void add_size(unsigned s, const raskroy::t_min_part &part);
	};

	// inline implementation
	inline t_other_size::t_other_size(void)
	{
	}

	inline unsigned t_other_size::num(const t_amounts& amounts) const
	{
		unsigned acc = 0;
		for (t_min_parts::const_iterator i = parts.begin(); i != parts.end(); i++)
			acc += amounts[i->offset];
		return acc;
	}

	inline void t_other_size::make_rashod(t_amounts& rashod, unsigned num, const t_amounts& amounts) const
	{
		for (t_min_parts::const_iterator i = parts.begin(); i != parts.end() && num > 0; i++)
		{
			unsigned amounti = amounts[i->offset];
			unsigned rashodi = num <= amounti ? num : amounti;
			rashod[i->offset] = rashodi;
			num -= rashodi;
		}
	}

	inline t_other_sizes::iterator t_other_sizes::find(scalar size)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->size == size)
				return i;
		return end();
	}

	inline void t_other_sizes::add_other_size(unsigned s, const t_min_part &part)
	{
		t_other_size os;
		os.size = part.rect.size[!s];
		os.parts.push_back(part);
		push_back(os);
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

	inline t_other_sizes::const_iterator t_other_sizes::watchMin(void) const
	{
		return min;
	}

	inline t_sizes::iterator t_sizes::find(scalar size)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->size == size)
				return i;
		return end();
	}

	inline void t_sizes::add_size(unsigned s, const t_min_part &part)
	{
		t_size size;
		size.size = part.rect.size[s];
		size.other_sizes.add_other_size(s, part);
		push_back(size);
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
		t_amounts res;
		res.resize(size());
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
#ifndef NVERBOSE
			std::cout << "d=" << d << std::endl;
			std::cout << "first=" << first << std::endl;
#endif
			if (d == 0)
				return 0;
			if (first || d < mind)
			{
				first = false;
				mind = d;
#ifndef NVERBOSE
				std::cout << "mind=" << mind << std::endl;
#endif
			}
		}
		assert(!first);
		return mind;
	}

}