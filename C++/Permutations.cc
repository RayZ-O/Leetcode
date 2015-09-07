// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

class Solution {
    void generate(vector<int> nums, int pos, vector<vector<int>>& per) {
        if (pos >= nums.size() -1) {
            per.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            generate(nums, pos + 1, per);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        generate(nums, 0, output);
        return output;
    }
};
