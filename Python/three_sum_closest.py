#!/usr/bin/env python
# Given an array S of n integers, find three integers in S such
# that the sum is closest to a given number, target. Return the
# sum of the three integers. You may assume that each input would
# have exactly one solution.

# For example, given array S = {-1 2 1 -4}, and target = 1.

# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return -1
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, len(nums) - 1
            while j < k:
                three_sum = nums[i] + nums[j] + nums[k]
                if three_sum == target:
                    return target
                elif abs(three_sum - target) < abs(closest - target):
                    closest = three_sum
                if three_sum > target:
                    k -= 1
                    while nums[k] == nums[k + 1] and j < k:
                        k -= 1
                else:
                    j += 1
                    while nums[j] == nums[j - 1] and j < k:
                        j += 1
        return closest
