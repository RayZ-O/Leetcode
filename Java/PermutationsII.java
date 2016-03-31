// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

public class PermutationsII {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> out = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        permuteUnique(nums, new ArrayList<Integer>(), used, out);
        return out;
    }

    void permuteUnique(int[] nums, List<Integer> cur, boolean[] used, List<List<Integer>> out) {
        if (cur.size() == nums.length) {
            out.add(new ArrayList<>(cur));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                cur.add(nums[i]);
                used[i] = true;
                permuteUnique(nums, cur, used, out);
                cur.remove(cur.size()-1);
                used[i] = false;
                while (i + 1 < nums.length && nums[i] == nums[i+1]) i++;
            }
        }
    }
}
