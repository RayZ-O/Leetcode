// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 
// and 3. It doesn't matter what you leave beyond the new length.

public class RemoveDuplicatesFromSortedArrayII {
    public int removeDuplicates(int[] nums) {
        int n = 1;
        int c = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1] && c++ >= 1) {
                continue;
            } 
            if (nums[i] != nums[i-1]) {
                c = 0;
            }
            nums[n++] = nums[i];
        }
        return n;
    }
}
