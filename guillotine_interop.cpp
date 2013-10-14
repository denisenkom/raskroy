// Python integration
#include "types.h"
#include "Raskroy.h"

using namespace Denisenko::Raskroy;

struct LayoutRect
{
    scalar x;
    scalar y;
    int can_rotate;
    unsigned int amount;
};

struct Sheet
{
    scalar x;
    scalar y;
};

extern "C" int layout2d(LayoutRect * layout_rects, unsigned int num, Sheet sheet)
{
    Parts parts;
    for (unsigned int i = 0; i <= num; i++)
    {
        LayoutRect * rect = &layout_rects[i];
        parts.push_back(Part(rect->x, rect->y,
                             rect->can_rotate, rect->amount));
    }
    Parts sheets;
    sheets.push_back(Part(sheet.x, sheet.y));
    Raskroy raskroy;
    raskroy.Begin(parts, sheets);
    Result res;
    int ret = raskroy.NextResult(res) ? 1 : 0;
    return ret;
}
