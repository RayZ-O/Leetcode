// Given a sorted integer array without duplicates, return the summary of its ranges.

// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary; 
        if (!nums.empty()) {
            int i = 0;
            int j = 0;
            while (j < nums.size()) {
                while (j + 1 < nums.size() && nums[j] + 1 == nums[j+1]) j++;
                if (i == j) summary.push_back(to_string(nums[j]));
                else summary.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                i = ++j;
            }
        }   
        return summary;
    }
};
