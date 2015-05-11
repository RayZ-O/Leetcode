// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums 
// being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(!size) {
            return 0;
        }
        int val = nums[0];
        int distinct = 0;
        int count = 1;
        for (int i = 1; i < size; ++i) {
            if (count == 1 && nums[i] == val) {
                count++;
                distinct++;                
                nums[distinct] = nums[i];
            } else if(nums[i] != val) {
                count = 1;
                val = nums[i];
                distinct++;
                nums[distinct] = nums[i];
            }
        }
        return distinct + 1;
    }
};