// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

class Solution {
public:
	// bit manipulation O(1) space
    int singleNumber1(vector<int>& nums) {
    	int result = 0;
        for(int n : nums) {
        	result ^= n;
        }
        return result;
    }
    
    // hash table O(n) space (2x slower)
    int singleNumber2(vector<int>& nums) {
     	unordered_set<int> hashTable;
     	 for(int n : nums) {
     	   	if (hashTable.find(n) != hashTable.end()) {
     	   		hashTable.erase(n);
     	   	} else {
     	   		hashTable.insert(n);
     	   	}
        }
        return *hashTable.begin();
    }
};