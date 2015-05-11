// Given a sorted array, remove the duplicates in place such 
// that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do 
// this in place with constant memory. 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
    	if(!size) {
    		return 0;
    	}
    	int val = nums[0];
    	int distinct = 0;
    	for (int i = 0; i < size; ++i) {
    		if (nums[i] == val) {
    			continue;
    		} else {
    			val = nums[i];
    			distinct++;
    			nums[distinct] = nums[i];
    		}
    	}
    	return distinct + 1;
    }
};