// Given an array nums containing n + 1 integers where each integer is between 1 and n
// (inclusive), prove that at least one duplicate number must exist. Assume that there
// is only one duplicate number, find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n^2).
// There is only one duplicate number in the array, but it could be repeated more than
// once.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int lower_count = count_if(nums.begin(), nums.end(), [mid](int i){return i <= mid;});
            if (lower_count > mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};
