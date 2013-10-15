// plain C interface to guillotine code
#include <iostream>
#include <vector>
#include <memory>
#include "types.h"
#include "Raskroy.h"

using namespace std;
using namespace Denisenko::Raskroy;


struct LayoutRect
{
    scalar size[2];
    int can_rotate;
    unsigned int amount;
};


struct Sheet
{
    scalar size[2];
};


// Type of the element
enum {
    ELEM_REMAIN = 0,
    ELEM_CUT = 1,
    ELEM_RECT = 2,  // a layed-out rectangle
    ELEM_SUBLAYOUT = 3,
};


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


enum {ALONG_X = 0, ALONG_Y = 1};


struct Layout
{
    int along;  // elements are located along: 0 - X, 1 - Y
    int num_elements;
    LayoutElement * elements;  // rects, cuts, remains and sub-layouts

    Layout() : num_elements(0), elements(0) {}

    Layout(int along, int num_elements) :
        along(along),
        num_elements(num_elements),
        elements(new LayoutElement[num_elements])
    {
    }

    void _free() {
        for (int i = 0; i < num_elements; i++) {
            if (elements[i].type == ELEM_SUBLAYOUT)
                elements[i].layout->_free();
        }
        delete [] elements;
        elements = 0;
        num_elements = 0;
    }

    ~Layout() {
        _free();
    }
};


LayoutElement * _vector_to_array(const vector<LayoutElement> & elements) {
    LayoutElement * array = new LayoutElement[elements.size()];
    for (size_t i = 0; i < elements.size(); i++) {
        array[i] = elements[i];
    }
    return array;
}


// forward declaration
Layout * _test(t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet)
{
    return 0;
}

Layout * _make_raskroy_layout(t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet);


Layout * _make_details_layout(t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet) {
    cout << "in make_details_layout" << endl;
    cout << " raskroy->s: " << raskroy->s << endl;
    cout << " cut_size: " << cut_size << endl;
    auto_ptr<Layout> detail_layout(new Layout);
    detail_layout->along = raskroy->s;
    cout << "detail_layout->along: " << detail_layout->along << endl;
    vector<LayoutElement> elements;
    scalar remain = sheet.size[!raskroy->s];
    cout << "remain: " << remain << endl;
    for (t_raskroy::t_details::const_iterator detail = raskroy->details.begin();
            detail != raskroy->details.end(); detail++) {
        for (unsigned i = 0; i < detail->num; i++) {
            LayoutElement element;
            element.type = ELEM_RECT;
            element.size = detail->size;
            elements.push_back(element);
            remain -= detail->size;
            if (remain > 0) {
                LayoutElement cut_el;
                cut_el.type = ELEM_CUT;
                cut_el.size = min(remain, cut_size);
                elements.push_back(element);
                remain -= cut_el.size;
            }
        }
    }
    if (remain >= 0) {
        LayoutElement remain_el;
        remain_el.size = remain;
        if (raskroy->watchRemain()) {
            remain_el.type = ELEM_SUBLAYOUT;
            Sheet subsheet = sheet;
            subsheet.size[raskroy->s] = remain;
            remain_el.layout = _make_raskroy_layout(raskroy->watchRemain(),
                                                    cut_size,
                                                    subsheet
                                                    );
        } else {
            remain_el.type = ELEM_REMAIN;
        }
        elements.push_back(remain_el);
    }
    detail_layout->elements = _vector_to_array(elements);
    detail_layout->num_elements = elements.size();
    return detail_layout.release();
}


Layout * _make_raskroy_layout(t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet) {
    cout << "in make_raskroy_layout" << endl;
    cout << " raskroy: " << raskroy << endl;
    cout << " raskroy->s: " << raskroy->s << endl;
    cout << " cut_size: " << cut_size << endl;
    auto_ptr<Layout> layout(new Layout);
    layout->along = raskroy->s;
    cout << "layout->along: " << layout->along << endl;
    scalar remain = sheet.size[!layout->along];
    cout << "remain: " << remain << endl;
    vector<LayoutElement> elements;
    for (t_raskroy * r = raskroy;
            r; r = r->watchRecurse()) {
        cout << "raskroy iteration" << endl;
        cout << "r: " << r << endl;
        cout << "r->s: " << r->s << endl;
        if (r->details.size()) {
            LayoutElement element;
            element.type = ELEM_SUBLAYOUT;
            element.size = r->cut;
            Sheet subsheet = sheet;
            subsheet.size[!layout->along] = element.size;
            cout << "calling make_details_layout" << endl;
            element.layout = _make_details_layout(r,
                                                  cut_size,
                                                  subsheet);
            elements.push_back(element);
            remain -= element.size;
            if (remain > 0) {
                LayoutElement cut_el;
                cut_el.type = ELEM_CUT;
                cut_el.size = min(remain, cut_size);
                elements.push_back(element);
            }
        }
    }
    if (remain >= 0) {
        LayoutElement remain_el;
        remain_el.type = ELEM_REMAIN;
        remain_el.size = remain;
        elements.push_back(remain_el);
    }
    layout->elements = _vector_to_array(elements);
    layout->num_elements = elements.size();
    cout << "returning" << endl;
    return layout.release();
}


//extern "C" int test(
//    LayoutRect * layout_rects,
//    unsigned int num,
//    Sheet sheet
//        ) {
//    cout << "in test" << num << " " << sheet.size[0] << endl;
//    for (unsigned int i = 0; i < num; i++)
//    {
//        cout << "rect " << layout_rects[i].size[0] << 'x' << layout_rects[i].size[1] << endl;
//    }
//    cout << "sheet " << sheet.size[0] << 'x' << sheet.size[1] << endl;
//}


extern "C" int layout2d(
    LayoutRect * layout_rects,
    unsigned int num,
    Sheet sheet,
    scalar cut_size,
    Layout ** res)
{
    Parts parts;
    for (unsigned int i = 0; i <= num; i++)
    {
        LayoutRect * rect = &layout_rects[i];
        parts.push_back(Part(rect->size[0], rect->size[1],
                             rect->can_rotate, rect->amount));
    }
    Parts sheets;
    sheets.push_back(Part(sheet.size[0], sheet.size[1]));
    Raskroy raskroy;
    raskroy.Begin(parts, sheets);
    Result outer_result;
    LayoutElement cut_el;
    cut_el.type = ELEM_CUT;
    cut_el.size = cut_size;
    int ret = raskroy.NextResult(outer_result) ? 1 : 0;
    if (ret) {
        cout << "ret:" << ret << endl;
        cout << "calling make_raskroy_layout" << endl;
        cout << "&outer_result.raskroy: " << &outer_result.raskroy << endl;
        cout << "cut_size: " << cut_size << endl;
        cout << "sheet: " << sheet.size[0] << 'x' << sheet.size[1] << endl;
        _make_raskroy_layout(&outer_result.raskroy,
                             cut_size,
                             sheet);
    }
    return ret;
}


extern "C" void free_layout(Layout * layout)
{
    delete layout;
}
