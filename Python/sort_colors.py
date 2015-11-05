#!/usr/bin/env python
# Given an array with n objects colored red, white or blue, sort them so that objects
# of the same color are adjacent, with the colors in the order red, white and blue.

# Here, we will use the integers 0, 1, and 2 to represent the color red, white,
# and blue respectively.

# Note:
# You are not suppose to use the library's sort function for this problem.

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i, j, k = 0, 0, len(nums) - 1
        while j <= k:
            if nums[j] == 0 and j > i:
                nums[j], nums[i] = nums[i], nums[j]
                i += 1
            elif nums[j] == 2:
                nums[j], nums[k] = nums[k], nums[j]
                k -= 1
            else:
                j += 1
