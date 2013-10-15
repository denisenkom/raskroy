import unittest
from guillotine import layout2d

class TestCase(unittest.TestCase):
    def test_simple(self):
        rect = {"size": (10, 10)}
        res = layout2d([rect], (10, 10))
        self.assertDictEqual(
            {"along": 0, "elements": [{"type": 2, "rect": rect, "size": 10}]},
            res)