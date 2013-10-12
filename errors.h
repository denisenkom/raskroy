#ifndef ErrorsH
#define ErrorsH

#include "types.h"

namespace Denisenko {
namespace Raskroy {

class CannotSetPartsException {
public:
	Parts *sheets;
	Sizes *sizes;
	Amounts *remains;

	CannotSetPartsException(Parts *sheets,
		Sizes sizes[],
		Amounts *remains)
		: sheets(sheets),
			sizes(sizes),
			remains(remains)
	{
	}
};

} // namespace Denisenko
} // namespace Raskroy

#endif // ErrorsH
