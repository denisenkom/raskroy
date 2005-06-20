#ifndef ErrorsH
#define ErrorsH

#include "types.h"

namespace Denisenko {
namespace Raskroy {

class err_cannot_set_parts {
public:
	t_parts &sheets;
	t_sizes *sizes;
	t_amounts &remains;

	err_cannot_set_parts(t_parts &sheets,
		t_sizes sizes[],
		t_amounts &remains)
		: sheets(sheets),
			sizes(sizes),
			remains(remains)
	{
	}
};

} // namespace Denisenko
} // namespace Raskroy

#endif // ErrorsH