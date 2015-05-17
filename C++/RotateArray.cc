// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note:
// Try to come up as many solutions as you can, there are at 
// least 3 different ways to solve this problem. 

class Solution {
public:
	// O(n) space
    void rotate1(vector<int>& nums, int k) {
    	int size = nums.size();
    	int offset = size - k % size;
    	vector<int> temp(size);
    	copy(nums.begin() + offset, nums.end(), temp.begin());
    	copy(nums.begin(), nums.begin() + offset, temp.begin() + size - offset);
    	swap(nums, temp);
    }

    // smart swap
    void rotate2(vector<int>& nums, int k) {
    	int n = nums.size();    	
    	for (int j = 0 ; k %= n; n -= k, j += k) {
    		for (int i = 0; i < k; i++)  {
    			 swap(nums[j + i], nums[n - k + i + j]);
    		}
    	}
    }

    // use reverse
    void rotate3(vector<int>& nums, int k) {
    	k = k % nums.size();
    	reverse(nums.begin(), nums.end());
    	reverse(nums.begin(), nums.begin() + k);
    	reverse(nums.begin() + k, nums.end());    	
    }

    // use STL rotate function directly, notice that std::rotate is left rotate
    void rotate4(vector<int>& nums, int k) {
		std::rotate(nums.begin(), nums.begin() + nums.size() - k % nums.size(), nums.end());
    }
};