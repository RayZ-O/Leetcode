// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

public class BinaryTreeInorderTraversal {
    public List<Integer> inorderTraversal(TreeNode root) {
       List<Integer> out = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        while (!st.isEmpty() || root != null) {
            if (root != null) {
                st.push(root);
                root = root.left;
            } else {
                TreeNode n = st.pop();
                out.add(n.val);
                root = n.right;
            }
        }
        return out;
    }
}
