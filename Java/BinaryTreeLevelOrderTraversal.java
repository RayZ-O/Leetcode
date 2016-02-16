// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left
// to right, level by level).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

public class BinaryTreeLevelOrderTraversal {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<>();
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
                out.add(l);
            }
        }
        return out;
    }
}
