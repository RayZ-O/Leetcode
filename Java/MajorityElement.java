// Given an array of size n, find the majority element. The majority element is the element that appears
// more than floor(n/2) times.

// You may assume that the array is non-empty and the majority element always exist in the array.

public class MajorityElement {
    public int majorityElement(int[] nums) {
        int majority = -1;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == majority) {
                count++;
            } else if (--count <= 0) {
                majority = nums[i];
                count = 1;
            }
        }
        return majority;
    }
}
