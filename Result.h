#ifndef ResultH
#define ResultH

#include <memory>
#include "types.h"

namespace Denisenko {
namespace Raskroy {

struct t_raskroy {
    struct t_detail {
        scalar size;
        unsigned num;
        const OtherSize * other_size;
    };

	typedef std::vector<t_detail> t_details;

	unsigned s; // разрез проходит перпендикул€рно этой стороне
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

	void CheckAndCalcStat(scalar cutThickness, const Rect& rect, Stat* outStat) const;

private:
	mutable t_raskroy *premain;
	mutable t_raskroy *precurse;
};

class t_result {
public:
	t_raskroy raskroy;
	Parts::iterator sheet;
	Stat Statistics;
	unsigned amount;

	t_result(void) : amount(0) {}
};


enum {ALONG_X = 0, ALONG_Y = 1};


// New format of layout results

// Type of the element
enum LayoutElementType {
    ELEM_REMAIN = 0,
    ELEM_CUT = 1,
    ELEM_RECT = 2,  // a layed-out rectangle
    ELEM_SUBLAYOUT = 3,
};


// should be compatible with C
struct LayoutElement
{
    scalar size;  // size of the element along layout axis
    int type;  // rect, remain, cut or sub-layout
    union {
        int rect_index;  // if type = ELEM_RECT this contains index of
                         // the rect from layout_rects
        struct Layout * layout;  // if type == ELEM_SUBLAYOUT this
                                 // is the pointer to sub-layout
    };
    LayoutElement() : type(ELEM_REMAIN), layout(0) {}
};


// Layout result
// should be compatible with C
struct Layout
{
    int along;  // elements are located along: 0 - X, 1 - Y
    size_t num_elements;
    LayoutElement * elements;  // rects, cuts, remains and sub-layouts

    Layout() : num_elements(0), elements(0) {}

    Layout(int along, int num_elements) :
        along(along),
        num_elements(num_elements),
        elements(new LayoutElement[num_elements])
    {
    }

    void clear() {
        for (int i = 0; i < num_elements; i++) {
            if (elements[i].type == ELEM_SUBLAYOUT)
                delete elements[i].layout;
        }
        delete [] elements;
        elements = 0;
        num_elements = 0;
    }

    ~Layout() {
        clear();
    }
};


struct LayoutElementBuilder
{
    scalar size;  // size of the element along layout axis
    LayoutElementType type;  // rect, remain, cut or sub-layout
    union {
        int rect_index;  // if type = ELEM_RECT this contains index of
                         // the rect from layout_rects
        struct LayoutBuilder * layout;  // if type == ELEM_SUBLAYOUT this
                                 // is the pointer to sub-layout
    };
    LayoutElementBuilder() : type(ELEM_REMAIN), layout(0) {}

    void _convert(LayoutElement & out);
};


struct LayoutBuilder {
    int axis;
    std::list<LayoutElementBuilder> elements;

    LayoutBuilder() : axis(0) {}

    void simplify();

    void append_sublayout(std::auto_ptr<LayoutBuilder> sublayout, scalar size) {
        if (sublayout->axis == axis) {
            elements.splice(elements.end(), sublayout->elements);
        }
        else {
            LayoutElementBuilder sublayout_el;
            sublayout_el.type = ELEM_SUBLAYOUT;
            sublayout_el.layout = sublayout.release();
            sublayout_el.size = size;
            elements.push_back(sublayout_el);
        }
    }

    void append_cut(scalar size) {
        LayoutElementBuilder cut_el;
        cut_el.type = ELEM_CUT;
        cut_el.size = size;
        elements.push_back(cut_el);
    }

    void append_remain(scalar size) {
        LayoutElementBuilder remain_el;
        remain_el.type = ELEM_REMAIN;
        remain_el.size = size;
        elements.push_back(remain_el);
    }

    void _free() {
        for (std::list<LayoutElementBuilder>::iterator i = elements.begin();
             i != elements.end(); i++)
        {
            if (i->type == ELEM_SUBLAYOUT)
                delete i->layout;
        }
    }

    ~LayoutBuilder() {
        _free();
    }

    void to_layout(Layout & out) {
        out.clear();
        out.along = axis;
        out.num_elements = elements.size();
        out.elements = new LayoutElement[out.num_elements];
        int i = 0;
        for (std::list<LayoutElementBuilder>::iterator pel = elements.begin();
             pel != elements.end(); pel++, i++)
        {
            pel->_convert(out.elements[i]);
        }
    }

};


// new preferred name for type
typedef t_result Result;

} // namespace Denisenko
} // namespace Raskroy

#endif // ResultH
