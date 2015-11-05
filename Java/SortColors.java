// Given an array with n objects colored red, white or blue, sort them so that objects
// of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white,
// and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

public class SortColors {
    public void sortColors(int[] nums) {
        if (nums == null || nums.length == 0)
            return;
        int zero_end = -1;
        for (;zero_end + 1 < nums.length && nums[zero_end + 1] == 0; zero_end ++);
        int two_beg = nums.length;
        for (;two_beg - 1 >= 0 && nums[two_beg -1] == 2; two_beg--);
        int k = zero_end + 1;
        while (k < two_beg) {
            if (nums[k] == 2) {
                nums[k] = nums[--two_beg];
                nums[two_beg] = 2;
            } else if (nums[k] == 0 && k > zero_end) {
                nums[k] = nums[++zero_end];
                nums[zero_end] = 0;
            } else {
                k++;
            }
        }
    }
}
