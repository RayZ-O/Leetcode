// Find all possible combinations of k numbers that add up to a number n, given that only numbers from
// 1 to 9 can be used and each combination should be a unique set of numbers.

// Ensure that numbers within the set are sorted in ascending order.


// Example 1:

// Input: k = 3, n = 7

// Output:

// [[1,2,4]]

// Example 2:

// Input: k = 3, n = 9

// Output:

// [[1,2,6], [1,3,5], [2,3,4]]

public class CombinationSumIII {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> out = new ArrayList<>();
        combinationSum(k, n, 1, new ArrayList<>(), out);
        return out;
    }

    void combinationSum(int k, int n, int i, List<Integer> cur, List<List<Integer>> out) {
        if (k == 0 || n < 0 || i > 9) {
            if (k == 0 && n == 0) {
                out.add(new ArrayList<>(cur));
            }
            return;
        }
        cur.add(i);
        combinationSum(k-1, n-i, i+1, cur, out);
        cur.remove(cur.size()-1);
        combinationSum(k, n, i+1, cur, out);
    }
}
