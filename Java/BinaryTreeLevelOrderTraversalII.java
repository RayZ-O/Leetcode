// Given a binary tree, return the bottom-up level order traversal of its nodes' values.
// (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

public class BinaryTreeLevelOrderTraversalII {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> out = new LinkedList<>();
        if (root != null) {
            Queue<TreeNode> q = new LinkedList<>();
            q.add(root);
            while (!q.isEmpty()) {
                int n = q.size();
                List<Integer> l = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    TreeNode t = q.remove();
                    l.add(t.val);
                    if (t.left != null) {
                        q.add(t.left);
                    }
                    if (t.right != null) {
                        q.add(t.right);
                    }
                }
                out.addFirst(l);
            }
        }
        return out;
    }
}
