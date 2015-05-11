// Given an array and a value, remove all instances of that value in place and return the new length.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
    	int j = size - 1;
    	for (int i = 0; i <= j; i++) {
    		if (nums[i] == val) {
    			while (j > i && nums[j] == val) {
    				j--;
    			}
    			nums[i] = nums[j];
    			j--;
    		}
    	}
    	return j + 1;
    }
};