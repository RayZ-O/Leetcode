// Given an array S of n integers, find three integers in S such
// that the sum is closest to a given number, target. Return the
// sum of the three integers. You may assume that each input would
// have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return -1;
        int closest = nums[0] + nums[1] + nums[2];
        int min_diff = abs(closest - target);
        int end = nums.size() - 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < end; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = end;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    closest = sum;
                    min_diff = diff;
                }
                if (sum > target) {
                    do {
                        k--;
                    } while (nums[k] == nums[k + 1] && j < k);
                } else {
                    do {
                        j++;
                    } while (nums[j] == nums[j - 1] && j < k);
                }
            }
        }
        return closest;
    }
};
