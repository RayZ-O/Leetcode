// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

public class SubsetsII {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> out = new ArrayList<>();
        generate(nums, 0, new ArrayList<Integer>(), out);
        return out;
    }

    void generate(int [] nums, int idx, List<Integer> cur, List<List<Integer>> out) {
        if (idx >= nums.length) {
            out.add(new ArrayList<>(cur));
            return;
        }
        int beg = idx;
        while (idx + 1 < nums.length && nums[idx+1] == nums[idx]) {
            idx++;
        }
        generate(nums, idx+1, cur, out);
        for (int i = beg; i <= idx; i++) {
            cur.add(nums[i]);
            generate(nums, idx+1, cur, out);
        }
        for (int i = beg; i <= idx; i++) {
            cur.remove(cur.size() - 1);
        }
    }
}
