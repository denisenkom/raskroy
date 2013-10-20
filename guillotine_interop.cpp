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


LayoutElement * _vector_to_array(const vector<LayoutElement> & elements) {
    LayoutElement * array = new LayoutElement[elements.size()];
    for (size_t i = 0; i < elements.size(); i++) {
        array[i] = elements[i];
    }
    return array;
}


// forward declaration
Layout * _make_raskroy_layout(t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet);


void _make_details_layout(Layout * detail_layout,
                              t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet) {
    cout << "in make_details_layout" << endl;
    cout << " raskroy->s: " << raskroy->s << endl;
    cout << " raskroy->cut: " << raskroy->cut << endl;
    cout << " cut_size: " << cut_size << endl;
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
    if (remain > 0) {
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
}


Layout * _make_raskroy_layout(t_raskroy * raskroy,
                              scalar cut_size,
                              Sheet sheet) {
    cout << "in make_raskroy_layout" << endl;
    cout << " raskroy: " << raskroy << endl;
    cout << "  s: " << raskroy->s << endl;
    cout << "  cut: " << raskroy->cut << endl;
    cout << "  details num: " << raskroy->details.size() << endl;
    cout << "  recurse: " << raskroy->watchRecurse() << endl;
    cout << "  remain: " << raskroy->watchRemain() << endl;
    cout << " cut_size: " << cut_size << endl;
    unique_ptr<Layout> layout(new Layout);
    if (raskroy->watchRecurse()) {
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
                unique_ptr<Layout> detail_layout(new Layout);
                _make_details_layout(layout.get(),
                                     r,
                                     cut_size,
                                     subsheet);
                element.layout = detail_layout.release();
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
        if (remain > 0) {
            LayoutElement remain_el;
            remain_el.type = ELEM_REMAIN;
            remain_el.size = remain;
            elements.push_back(remain_el);
        }
        layout->elements = _vector_to_array(elements);
        layout->num_elements = elements.size();
    }
    else {
        _make_details_layout(layout.get(), raskroy, cut_size, sheet);
    }
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


#ifdef _MSC_VER
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif


extern "C" int DLLEXPORT layout2d(
    LayoutRect * layout_rects,
    unsigned int num,
    scalar sheet_x,
    scalar sheet_y,
    scalar cut_size,
    Layout ** res)
{
    Sheet sheet;
    sheet.size[0] = sheet_x;
    sheet.size[1] = sheet_y;
    Parts parts;
    for (unsigned int i = 0; i < num; i++)
    {
        LayoutRect * rect = &layout_rects[i];
        parts.push_back(Part(rect->size[0], rect->size[1],
                             rect->can_rotate, rect->amount));
    }
    Parts sheets;
    sheets.push_back(Part(sheet.size[0], sheet.size[1]));
    Raskroy raskroy;
    raskroy.put_SawThickness(cut_size);
    raskroy.Begin(parts, sheets);
    Result outer_result;
    int ret = raskroy.NextResult(outer_result) ? 1 : 0;
    if (ret) {
        cout << "ret:" << ret << endl;
        cout << "calling make_raskroy_layout" << endl;
        cout << "&outer_result.raskroy: " << &outer_result.raskroy << endl;
        cout << "cut_size: " << cut_size << endl;
        cout << "sheet: " << sheet.size[0] << 'x' << sheet.size[1] << endl;
        *res = _make_raskroy_layout(&outer_result.raskroy,
                                    cut_size,
                                    sheet);
    }
    return ret;
}


extern "C" int DLLEXPORT new_layout2d(
    LayoutRect * layout_rects,
    unsigned int num,
    scalar sheet_x,
    scalar sheet_y,
    scalar cut_size,
    Layout ** res)
{
    Rect sheet;
    sheet.Size[0] = sheet_x;
    sheet.Size[1] = sheet_y;
    Parts parts;
    for (unsigned int i = 0; i < num; i++)
    {
        LayoutRect * rect = &layout_rects[i];
        Part part(rect->size[0], rect->size[1],
                  rect->can_rotate, rect->amount);
        part.Tag = (int)i;
        parts.push_back(part);
    }
    Raskroy raskroy;
    LayoutBuilder layout_builder;
    int ret = raskroy.new_optimize(sheet, parts, cut_size, layout_builder) ? 1 : 0;
    if (ret) {
        unique_ptr<Layout> layout(new Layout);
        layout_builder.simplify();
        layout_builder.to_layout(*layout);
        *res = layout.release();
        // report back new amounts
        for (int i = 0; i < parts.size(); i++) {
            layout_rects[i].amount = parts[i].Amount;
        }
    }
    return ret;
}


extern "C" void DLLEXPORT free_layout(Layout * layout)
{
    delete layout;
}
