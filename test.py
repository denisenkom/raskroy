import unittest
from guillotine import layout2d

class TestCase(unittest.TestCase):
    def test_simple(self):
        rect = {"size": (10, 10)}
        res = layout2d([rect], (10, 10))
        self.assertDictEqual(
            {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 10}]},
            res)

        rect = {"size": (5, 10), "amount": 2}
        print layout2d([rect], (10, 10))
        #self.assertDictEqual(
        #    {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 5},
        #                              {"type": 2, "rect": rect, "size": 5}]},
        #    layout2d([rect], (10, 10)))

    def test_skinny_detail(self):
        # +-+---------+
        # + +    2    +
        # + +         +
        # +1+---------+
        # + +    2    +
        # + +         +
        # + +---------+
        # +-+---------+
        rect1 = {"size": (1, 10)}
        rect2 = {"size": (9, 4), "num": 2}
        res = layout2d([rect1, rect2], (10, 10))
        print res
