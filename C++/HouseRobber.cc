// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint
// stopping you from robbing each of them is that adjacent houses have
// security system connected and it will automatically contact the police
// if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money
// of each house, determine the maximum amount of money you can rob tonight
// without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int prev_max = nums[0];
        int max_money= max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int last = max_money;
            max_money = max(prev_max + nums[i], max_money);
            prev_max = last;
        }
        return max_money;
    }
};
