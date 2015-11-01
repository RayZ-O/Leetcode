// Given an array S of n integers, are there elements a, b, c in S
// such that a + b + c = 0? Find all unique triplets in the array
// which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order.
// (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        int size = nums.size() - 1;
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int low = i + 1;
            int high = size;
            while (low < high) {
                if (nums[low] + nums[high] < target) low++;
                else if (nums[low] + nums[high] > target) high--;
                else {
                    output.push_back({nums[i], nums[low], nums[high]});
                    int cur_low = low;
                    while (nums[low] == nums[cur_low]) low++;
                }
            }
        }
        return output;
    }
};
