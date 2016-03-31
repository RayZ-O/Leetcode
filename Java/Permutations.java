// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

public class Permutations {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> out = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        permute(nums, new ArrayList<Integer>(), used, out);
        return out;
    }

    void permute(int[] nums, List<Integer> cur, boolean[] used, List<List<Integer>> out) {
        if (cur.size() == nums.length) {
            out.add(new ArrayList<>(cur));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                cur.add(nums[i]);
                used[i] = true;
                permute(nums, cur, used, out);
                cur.remove(cur.size()-1);
                used[i] = false;
            }
        }
    }
}
