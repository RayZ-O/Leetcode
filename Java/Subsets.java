// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

public class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> out = new ArrayList<>();
        int mask = 1 << nums.length;
        for (int i = 0; i < mask; i++) {
            List<Integer> l = new ArrayList<>();
            for (int j = 0; j < nums.length; j++) {
                if ((i & 1 << j) > 0) {
                    l.add(nums[j]);
                }
            }
            out.add(l);
        }
        return out;
    }
}
