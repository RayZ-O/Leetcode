// Given an array of integers, find out whether there are two distinct indices i and j in
// the array such that the difference between nums[i] and nums[j] is at most t and the
// difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        multiset<int> vals;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                vals.erase(vals.find(nums[i - k - 1]));
            }
            auto lower = vals.lower_bound(nums[i] - t);
            if (lower != vals.end() && *lower <= static_cast<long>(nums[i]) + t) {
                return true;
            }
            vals.insert(nums[i]);
        }
        return false;
    }
};
