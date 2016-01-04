// Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

class Solution {
    void findRange(vector<string>& output, int prev, int cur) {
        if (prev + 1 < cur) {
            if (prev + 2 == cur) {
                output.push_back(to_string(prev + 1));
            } else {
                output.push_back(to_string(prev + 1) + "->" + to_string(cur - 1));
            }
        }
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> output;
        int u = nums.empty() ? upper + 1 : nums[0];
        findRange(output, lower - 1, u);
        for (int i = 1; i < nums.size(); i++) {
            findRange(output, nums[i - 1], nums[i]);
        }
        findRange(output, nums[nums.size() - 1], upper + 1);
        return output;
    }
};
