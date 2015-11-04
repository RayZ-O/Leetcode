// Given an array of n integers nums and a target, find the number of index
// triplets i, j, k with 0 <= i < j < k < n that satisfy the condition
// nums[i] + nums[j] + nums[k] < target.

// For example, given nums = [-2, 0, 1, 3], and target = 2.

// Return 2. Because there are two triplets which sums are less than 2:

// [-2, 0, 1]
// [-2, 0, 3]

public class ThreeSumSmaller {
    public int threeSumSmaller(int[] nums, int target) {
        if (nums.length < 3)
            return 0;
        int count = 0;
        int end = nums.length - 1;
        Arrays.sort(nums);
        for (int i = 0; i < end; i++) {
            int j = i + 1;
            int k = end;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < target) {
                    count += k - j;
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
}
