// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

public class Combinations {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> out = new ArrayList<>();
        generate(1, n, k, new ArrayList<Integer>(), out);
        return out;
    }

    void generate(int i, int n, int k, ArrayList<Integer> cur, List<List<Integer>> out) {
        if (n - i + 1 < k) {
            return;
        }
        if (k == 0) {
            out.add(new ArrayList<Integer>(cur));
            return;
        }
        cur.add(i);
        generate(i+1, n, k-1, cur, out);
        cur.remove(cur.size()-1);
        generate(i+1, n, k, cur, out);
    }
}
