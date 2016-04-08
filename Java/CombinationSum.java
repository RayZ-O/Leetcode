// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where 
// the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

public class CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> out = new ArrayList<>();
        Arrays.sort(candidates);
        combinationSum(candidates, 0, target, new ArrayList<Integer>(), out);
        return out;
    }

    void combinationSum(int[] candidates, int idx, int target, List<Integer> cur, List<List<Integer>> out) {
        if (target == 0) {
            out.add(new ArrayList<>(cur));
            return;
        }
        for (int i = idx; i < candidates.length; i++) {
            if (i > 0 && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            cur.add(candidates[i]);
            combinationSum(candidates, i, target - candidates[i], cur, out);
            cur.remove(cur.size()-1);
        }
    }

    static public void main(String[] args) {
        Solution s = new Solution();
        s.combinationSum(new int[]{2,3,6,7}, 7);
    }
}
