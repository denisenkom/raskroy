namespace raskroy {

	class perebor {
		t_other_sizes::const_iterator i;
		t_other_sizes::const_iterator end;
		t_amounts &remains;

		scalar recursive(scalar size, t_amounts &rashod);

	public:
		scalar remain;
		scalar saw_thickness;

		perebor(t_amounts &remains, scalar saw_thickness);
		bool make(const t_size &size, scalar other_size, t_stat&, t_raskroy&, t_amounts &rashod);
	};
}