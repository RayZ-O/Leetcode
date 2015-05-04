// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, 
// where index1 must be less than index2. Please note that your returned answers(both index1 and index2) 
// are not zero-based.
// Assume that each input would have exactly one solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key is the number in nums, value is the corresponding index
        unordered_map<int, int> hashtable;
        vector<int> result;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()) {
                result = { it->second + 1, i + 1 };
                break;
            } else {
                hashtable.emplace(nums[i], i);
            }
        }
        return result;
    }
};