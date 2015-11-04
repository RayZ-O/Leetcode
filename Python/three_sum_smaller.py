# Given an array of n integers nums and a target, find the number of index
# triplets i, j, k with 0 <= i < j < k < n that satisfy the condition
# nums[i] + nums[j] + nums[k] < target.

# For example, given nums = [-2, 0, 1, 3], and target = 2.

# Return 2. Because there are two triplets which sums are less than 2:

# [-2, 0, 1]
# [-2, 0, 3]

class Solution(object):
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        count = 0
        nums.sort()
        for i, elem in enumerate(nums):
            j, k = i + 1, len(nums) - 1
            while j < k:
                if elem + nums[j] + nums[k] < target:
                    count += k - j
                    j += 1
                else:
                    k -= 1
        return count

