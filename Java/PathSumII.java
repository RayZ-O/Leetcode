// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

public class PathSumII {
    public void pathSum(TreeNode root, int sum, List<Integer> cur, List<List<Integer>> out) {
        if (root == null) {
            return;
        }
        sum -= root.val;
        cur.add(root.val);
        if (root.left == null && root.right == null && sum == 0) {
            out.add(new ArrayList(cur));
        }
        pathSum(root.left, sum, cur, out);
        pathSum(root.right, sum, cur, out);
        cur.remove(cur.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> out = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        pathSum(root, sum, cur, out);
        return out;
    }
}
