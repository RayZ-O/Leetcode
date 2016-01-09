// Note: This is an extension of House Robber.

// After robbing those houses on that street, the thief has found himself a new place for
// his thievery so that he will not get too much attention. This time, all houses at this
// place are arranged in a circle. That means the first house is the neighbor of the last
// one. Meanwhile, the security system for these houses remain the same as for those in the
// previous street.

// Given a list of non-negative integers representing the amount of money of each house,
// determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
    int rob(vector<int>& nums, int beg, int end) {
        int prev_max = 0;
        int max_money= 0;
        for (int i = beg; i < end; i++) {
            int last = max_money;
            max_money = max(prev_max + nums[i], max_money);
            prev_max = last;
        }
        return max_money;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }
};
