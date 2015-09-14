// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4]. 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        auto lowIt=std::lower_bound (nums.begin(), nums.end(), target);
        auto upIt= std::upper_bound (nums.begin(), nums.end(), target);
        int low = *lowIt == target ? lowIt - nums.begin() : -1;
        int up = *(upIt - 1) == target ? upIt - nums.begin() - 1 : -1;
        return {low, up};
    }
};