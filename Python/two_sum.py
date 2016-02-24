#!/usr/bin/env python

# Given an array of integers, return indices of the two numbers such that they add up to a specific target.

# You may assume that each input would have exactly one solution.

# Example:
# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dc = {}
        for i in range(len(nums)):
            n = target - nums[i]
            if n in dc:
                return [dc[n], i]
            else:
                dc[nums[i]] = i
