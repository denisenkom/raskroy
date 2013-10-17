import unittest
from guillotine import layout2d

class TestCase(unittest.TestCase):
    def test_simple(self):
        self.maxDiff = None
        rect = {"size": (10, 10)}
        res = layout2d([rect], (10, 10))
        self.assertIn(res["along"], (0, 1))
        if res["along"] == 0:
            self.assertDictEqual(
                {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 10}]},
                res)
        else:
            self.assertDictEqual(
                {"along": 1, "elements": [{"type": 2, "rect": rect, "size": 10}]},
                res)

        # two identical rectangles along x axis
        rect = {"size": (5, 10), "amount": 2}
        self.assertDictEqual(
            {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 5},
                                      {"type": 1, "size": 0},
                                      {"type": 2, "rect": rect, "size": 5}]},
            layout2d([rect], (10, 10)))

    def test_rectangle_with_remain(self):
        self.maxDiff = None
        rect = {"size": (5, 10), "amount": 2}
        self.assertDictEqual(
            {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 5},
                                      {"type": 1, "size": 0},
                                      {"type": 2, "rect": rect, "size": 5},
                                      {"type": 1, "size": 0},
                                      {"type": 0, "size": 2},
                                      ]},
            layout2d([rect], (12, 10)))

    def test_rectangle_with_remains(self):
        self.maxDiff = None
        rect = {"size": (5, 10), "amount": 2}
        det_layout = {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 5},
                                               {"type": 1, "size": 0},
                                               {"type": 2, "rect": rect, "size": 5},
                                               ]}
        left_layout = {"along": 1, "elements": [
            {"type": 3, "size": 10, "layout": det_layout},
            {"type": 1, "size": 0},
            {"type": 0, "size": 1}]}
        self.assertDictEqual(
            {"along": 0, "elements": [
                {"type": 3, "size": 10, "layout": left_layout},
                {"type": 1, "size": 0},
                {"type": 0, "size": 2}
                ]
                },
            layout2d([rect], (12, 11)))

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
        self.maxDiff = None
        self.assertDictEqual(
            {"along": 0, "elements": [
                {"type": 2, "rect": rect1, "size": 1},
                {"type": 1, "size": 0},
                {"type": 3, "layout": {
                    "along": 1, "elements": [
                        {"type": 2, "rect": rect2, "size": 4},
                        {"type": 1, "size": 0},
                        {"type": 2, "rect": rect2, "size": 4},
                        {"type": 1, "size": 0},
                        {"type": 0, "size": 2},
                        ]
                    }, "size": 9}]},
            res)
