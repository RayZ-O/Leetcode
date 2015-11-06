// Given a set of distinct integers, nums, return all possible subsets.

// Note:

//     Elements in a subset must be in non-descending order.
//     The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int max = 1 << nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for (int i = 0; i < max; i++) {
            vector<int> subset;
            for (int k = i, j = 0; k; k >>= 1, j++) {
                if (k & 1)
                    subset.push_back(nums[j]);
            }
            output.push_back(subset);
        }
        return output;
    }
};
