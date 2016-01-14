// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// Example:
// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

// Note:
// You may assume all input has valid answer.

class Solution {
    void partition(vector<int>& v, int val) {
        int i = 0, j = 0, k = v.size() - 1;
        while (j <= k) {
            if (v[j] < val) {
                swap(v[i++], v[j++]);
            } else if (v[j] > val) {
                swap(v[j++], v[k--]);
            } else {
                j++;
            }
        }
    }
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        partition (nums, nums[mid]);
        vector<int> temp(n);
        for (int i = 0; i < mid; i++) {
            temp[i*2] = nums[mid-i-1];
            temp[i*2+1] = nums[n-i-1];
        }
        if (n % 2) {
            temp[n-1] = nums[mid];
        }
        nums.swap(temp);
    }
};
