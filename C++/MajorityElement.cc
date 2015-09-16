// Given an array of size n, find the majority element. The majority element is the 
// element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist 
// in the array.

class Solution {
public:
    // hash table
    int majorityElement1(vector<int>& nums) {
        if (nums.empty()) return -1;
        unordered_map<int, int> table;
        int m = nums.size() / 2;
        int candidate = nums[0];
        for (int i : nums) {
            if (table.find(i) == table.end()) table.emplace(i, 1);
            else if (++table[i] > m) candidate = i;
        }
        // if majority element not always exist 
        // if (table[candidate] <= m) {
        //     candidate = -1;
        // }
        return candidate;
    }

    // Boyer–Moore majority vote algorithm
    int majorityElement2(vector<int>& nums) {
        if (nums.empty()) return -1;
        int candidate;
        int count = 0;
        for (int i: nums) {
            if (!count) {
                candidate = i;
                count = 1;
            } else {
                count += candidate == i ? 1 : -1;
            }
        }
        // if majority element not always exist 
        // for (int i : nums) {
        //    if (candidate == i) count++;
        // }
        // if (count <= nums.size() / 2) candidate = -1;
        return candidate;
    }

};