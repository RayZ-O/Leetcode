#!/usr/bin/env python

# Determine whether an integer is a palindrome. Do this without extra space.

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        return x >= 0 and int(str(x)[::-1]) == x
