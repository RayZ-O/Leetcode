// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

public class PascalsTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lli = new ArrayList<>();
        if (numRows < 1) {
            return lli;
        }
        for (int i = 0; i < numRows; i++) {
            List<Integer> li = new ArrayList<>();
            li.add(1);
            for (int j = 1; j < i; j++) {
                li.add(lli.get(i-1).get(j-1) + lli.get(i-1).get(j));
            }
            if (i > 0) {
            	li.add(1);
            }
            lli.add(li);
        }
        return lli;
    }
}
