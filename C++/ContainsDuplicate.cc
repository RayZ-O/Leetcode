// Given an array of integers, find if the array contains any duplicates. Your function should 
// return true if any value appears at least twice in the array, and it should return false if 
// every element is distinct. 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_table;
        for (int n : nums) {
        	if (hash_table.find(n) != hash_table.end()) {
        		return true;
        	}
        	hash_table.insert(n);
        }
        return false;
    }
};