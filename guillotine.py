import ctypes
import os

path = os.path.abspath(os.path.join(os.path.dirname(__name__), "libguillotine_interop.so"))
print path
lib = ctypes.cdll.LoadLibrary(path)

class _LayoutRect(ctypes.Structure):
    _fields_ = [("x", ctypes.c_longlong),
                ("y", ctypes.c_longlong),
                ("can_rotate", ctypes.c_int),
                ("amount", ctypes.c_uint),
                ]


class _Sheet(ctypes.Structure):
    _fields_ = [("x", ctypes.c_longlong),
                ("y", ctypes.c_longlong)]

def layout2d(rects, sheet):
    conv_rects = (_LayoutRect * len(rects))()
    for i, rect in enumerate(rects):
        conv_rects[i].x = rect["size"][0]
        conv_rects[i].y = rect["size"][1]
        conv_rects[i].amount = rect.get("amount", 1)
        conv_rects[i].can_rotate = rect.get("can_rotate", False)
    conv_sheet = _Sheet(x=sheet[0], y=sheet[1])
    return lib.layout2d(conv_rects, ctypes.c_uint(len(conv_rects)), conv_sheet)
