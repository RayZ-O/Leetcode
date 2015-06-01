// Given an array of integers and an integer k, find out whether there there are two distinct 
// indices i and j in the array such that nums[i] = nums[j] and the difference between i and j 
// is at most k. 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_table;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
        	if (hash_table.find(nums[i]) != hash_table.end() && i - hash_table[nums[i]] <= k)
        		return true;
        	else
        		hash_table[nums[i]] = i;        		
        }
        return false;
    }
};