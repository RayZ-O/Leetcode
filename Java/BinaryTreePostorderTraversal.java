// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

public class BinaryTreePostorderTraversal {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        Stack<TreeNode> cur = new Stack<>();
        Stack<TreeNode> res = new Stack<>();
        if (root != null) {
            cur.push(root);
        }
        while (!cur.isEmpty()) {
            TreeNode n = cur.pop();
            res.push(n);
            if (n.left != null) {
                cur.push(n.left);
            }
            if (n.right !=null) {
                cur.push(n.right);
            }
        }
        while (!res.isEmpty()) {
            out.add(res.pop().val);
        }
        return out;
    }
}
