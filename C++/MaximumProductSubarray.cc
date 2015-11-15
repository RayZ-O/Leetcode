// Find the contiguous subarray within an array (containing at least
// one number) which has the largest product.

// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max_product = nums[0];
        int cur_max = nums[0];
        int cur_min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int m = cur_max * nums[i];
            int n = cur_min * nums[i];
            cur_max = max(max(m, n), nums[i]);
            cur_min = min(min(m, n), nums[i]);
            max_product = max(max_product, cur_max);
        }
        return max_product;
    }
};
