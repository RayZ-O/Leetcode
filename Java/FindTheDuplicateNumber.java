// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
// find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.

public class FindTheDuplicateNumber {
    public int findDuplicate(int[] nums) {
        int l = 1, h = nums.length;
        while (l < h) {
            int mid = l + (h - l) / 2;
            long count = Arrays.stream(nums).filter((int n)->n <= mid).count();
            if (count <= mid) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return h;
    }
}
