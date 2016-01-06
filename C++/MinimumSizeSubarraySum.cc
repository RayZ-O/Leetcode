// Given an array of n positive integers and a positive integer s, find the minimal
// length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_length = nums.size() + 1;
        int sum = 0;
        int beg = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= s) {
                return 1;
            }
            sum += nums[i];
            while (sum >= s) {
                min_length = min(i - beg + 1, min_length);
                sum -= nums[beg];
                beg++;
            }
        }
        return min_length == nums.size() + 1 ? 0 : min_length;
    }
};
