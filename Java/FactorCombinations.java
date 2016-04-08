// Numbers can be regarded as product of its factors. For example,

// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.

// Note: 
// Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], 
// not [6, 2].
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Examples: 
// input: 1
// output: 
// []
// input: 37
// output: 
// []
// input: 12
// output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// input: 32
// output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]

public class FactorCombinations {
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> out = new ArrayList<>();
        getFactors(n, 2, new ArrayList<Integer>(), out);
        return out;
    }

    void getFactors(int n, int fac, List<Integer> cur, List<List<Integer>> out) {
        if (n == 1) {
            if (cur.size() > 1) {
                out.add(new ArrayList<>(cur));
            }
            return;
        }
        for (int i = fac; i <= n; i++) {
            if (n % i == 0) {
                cur.add(i);
                getFactors(n/i, i, cur, out);
                cur.remove(cur.size()-1);
            }
        }
    }
}
