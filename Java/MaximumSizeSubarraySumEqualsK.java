// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If
// there isn't one, return 0 instead.

// Example 1:
// Given nums = [1, -1, 5, -2, 3], k = 3,
// return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

// Example 2:
// Given nums = [-2, -1, 2, 1], k = 1,
// return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

public class MaximumSizeSubarraySumEqualsK {
    public int maxSubArrayLen(int[] nums, int k) {
        int[] sums = new int[nums.length+1];
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 0);
        int maxLen = 0;
        for (int i = 1; i < sums.length; i++) {
            sums[i] = sums[i-1] + nums[i-1];
            maxLen = Math.max(maxLen, i - mp.getOrDefault(sums[i] - k, i));
            mp.putIfAbsent(sums[i], i);
        }
        return maxLen;
    }
}
