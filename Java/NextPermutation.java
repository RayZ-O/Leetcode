// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation 
// of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in 
//     ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the 
// right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

public class NextPermutation {
    public void nextPermutation(int[] nums) {
        int k = nums.length - 2;
        while (k >= 0 && nums[k] >= nums[k+1]) {
            k--;
        }
        if (k >= 0) {
            int l = nums.length - 1;
            while (l > k && nums[k] >= nums[l]) {
                l--;
            }
            swap(nums, k, l);
        }
        reverse(nums, k+1, nums.length-1);
    }

    void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void reverse(int[] nums, int l, int r) {
        while (l < r) {
            swap(nums, l++, r--);
        }
    }
}
