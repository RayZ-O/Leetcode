// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations 
// in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6]

public class CombinationSumII {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
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
            if (candidates[i] > target) {
                break;
            }
            cur.add(candidates[i]);
            combinationSum(candidates, i+1, target - candidates[i], cur, out);
            cur.remove(cur.size()-1);
            while (i + 1 < candidates.length && candidates[i] == candidates[i+1]) i++; 
        }
    }
}
