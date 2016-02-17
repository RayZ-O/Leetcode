#!/usr/bin/env python

# Reverse digits of an integer.

# Example1: x = 123, return 321
# Example2: x = -123, return -321

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = int(str(abs(x))[::-1])
        return (1 if x >= 0 else -1) * (0 if r > pow(2, 31) - 1 else r)
