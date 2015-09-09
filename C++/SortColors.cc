// Given an array with n objects colored red, white or blue, sort them so that objects of the same 
// color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(j > i) {
            while (nums[i] == 0 && j > i) i++;
            while (nums[j] != 0 && j > i) j--;
            swap(nums[i], nums[j]);
        }
        j = nums.size() - 1;
        while(j > i) {
            while (nums[j] == 2 && j > i) j--;
            while (nums[i] != 2 && j > i) i++;
            swap(nums[i], nums[j]);
        }
    }
};
