// Find the contiguous subarray within an array (containing at least one number)
// which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur_sum = max(nums[i], cur_sum + nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};
