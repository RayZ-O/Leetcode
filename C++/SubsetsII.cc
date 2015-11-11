// Given a collection of integers that might contain duplicates, nums,
// return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
    void collectSubset(int start, vector<int>& cur, vector<vector<int>>& output, vector<int>& nums) {
        output.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            collectSubset(i + 1, cur, output, nums);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        collectSubset(0, cur, output, nums);
        return output;
    }
};
