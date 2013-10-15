import ctypes
import os

path = os.path.abspath(os.path.join(os.path.dirname(__name__), "libguillotine_interop.so"))
lib = ctypes.cdll.LoadLibrary(path)
_scalar = ctypes.c_longlong

ELEM_REMAIN = 0
ELEM_CUT = 1
ELEM_RECT = 2  # a layed-out rectangle
ELEM_SUBLAYOUT = 3


class _LayoutRect(ctypes.Structure):
    _fields_ = [("size", _scalar * 2),
                ("can_rotate", ctypes.c_int),
                ("amount", ctypes.c_uint),
                ]


class _Sheet(ctypes.Structure):
    #_fields_ = [("size", _scalar * 2)]
    _fields_ = [("x", _scalar),
                ("y", _scalar)]


class _Layout(ctypes.Structure):
    pass


class _LayoutElement(ctypes.Structure):
    class _LayoutElementUnion(ctypes.Union):
        _fields_ = [("rect_index", ctypes.c_int),
                    ("layout", ctypes.POINTER(_Layout))]
    _fields_ = [("size", _scalar),
                ("type", ctypes.c_int),
                ("u", _LayoutElementUnion)]


_Layout._fields_ = [("along", ctypes.c_int),
                    ("num_elements", ctypes.c_int),
                    ("elements", ctypes.POINTER(_LayoutElement))]


def _conv_layout(clayout, rects):
    return {"along": clayout.along,
            "elements": [_conv_element(clayout.elements[i], rects)
                         for i in xrange(clayout.num_elements)]}


def _conv_element(celement, rects):
    element = {"size": celement.size,
               "type": celement.type,
               }
    if celement.type == ELEM_RECT:
        element["rect"] = rects[celement.u.rect_index]
    elif celement.type == ELEM_SUBLAYOUT:
        element["layout"] = _conv_layout(celement.u.layout.contents, rects)
    return element


def layout2d(rects, sheet, cut_size=0):
    conv_rects = (_LayoutRect * len(rects))()
    for i, rect in enumerate(rects):
        conv_rects[i].size[0] = rect["size"][0]
        conv_rects[i].size[1] = rect["size"][1]
        conv_rects[i].amount = rect.get("amount", 1)
        conv_rects[i].can_rotate = rect.get("can_rotate", False)
    conv_sheet = _Sheet()
    conv_sheet.x = sheet[0]
    conv_sheet.y = sheet[1]
    playout = ctypes.POINTER(_Layout)()
    print ctypes.sizeof(conv_sheet)
    print ctypes.sizeof(conv_rects)
    #lib.test(ctypes.byref(conv_rects[0]), ctypes.c_uint(len(rects)), conv_sheet)
    ret = lib.layout2d(ctypes.byref(conv_rects[0]),
                       ctypes.c_uint(len(conv_rects)),
                       conv_sheet,
                       _scalar(cut_size),
                       ctypes.byref(playout),
                       )
    try:
        if ret:
            return _conv_layout(playout.contents, rects)
        else:
            return None
    finally:
        lib.free_layout(playout)
