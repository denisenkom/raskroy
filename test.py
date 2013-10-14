import unittest
from guillotine import layout2d

class TestCase(unittest.TestCase):
    def test_simple(self):
        layout2d([{"size": (10, 10)}], (10, 10))
