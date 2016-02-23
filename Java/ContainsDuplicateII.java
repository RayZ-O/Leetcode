// Given an array of integers and an integer k, find out whether there are two distinct indices i and j
// in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

public class ContainsDuplicateII {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (mp.get(nums[i]) != null && i - mp.get(nums[i]) <= k) {
                return true;
            }
            mp.put(nums[i], i);
        }
        return false;
    }
}
