// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

public class RotateArray {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    void reverse(int[] nums, int beg, int end) {
        while (beg < end) {
            int temp = nums[beg];
            nums[beg] = nums[end];
            nums[end] = temp;
            beg++;
            end--;
        }
    }
}
