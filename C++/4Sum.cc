// Given an array S of n integers
// Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        if (nums.size() < 4) {
            return output;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int t3 = target - nums[i];
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int t2 = t3 - nums[j];
                int low = j + 1;
                int high = n - 1;
                while (low < high) {
                    int sum = nums[low] + nums[high];
                    if (sum == t2) {
                        output.emplace_back(vector<int>{nums[i], nums[j], nums[low], nums[high]});
                        for (int cur = nums[low]; low < high && nums[low] == cur; low++);
                    } else {
                        sum > t2 ? high-- : low++;
                    }

                }
            }
        }
        return output;
    }
};
