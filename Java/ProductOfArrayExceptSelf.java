// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to 
// the product of all the elements of nums except nums[i].

// Solve it without division and in O(n).

// For example, given [1,2,3,4], return [24,12,8,6].

public class ProductOfArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        if (nums.length < 2) {
            return nums;
        }
        int[] out = new int[nums.length];
        out[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            out[i] = nums[i-1] * out[i-1];
        }
        int pre = 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            pre *= nums[i+1];
            out[i] *= pre;
        }
        return out;
    }
}
