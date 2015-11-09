// Given a collection of numbers that might contain duplicates,
// return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

class Solution {
    bool nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i < 0) {
            return false;
        }
        int j = nums.size() - 1;
        while (j > i && nums[i] >= nums[j])
            j--;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        do {
            output.push_back(nums);
        } while (nextPermutation(nums));
        return output;
    }
};
