#!/usr/bin/env python3

# Given two numbers represented as strings, return multiplication of the numbers as a string.

# Note: The numbers can be arbitrarily large and are non-negative.

class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        return str(int(num1) * int(num2))
