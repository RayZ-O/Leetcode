// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

public class BinaryTreePreorderTraversal {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        if (root != null) {
            Stack<TreeNode> st = new Stack<>();
            st.push(root);
            while (!st.isEmpty()) {
                TreeNode n = st.pop();
                while (n != null) {
                    out.add(n.val);
                    if (n.right != null) {
                        st.push(n.right);
                    }
                    n = n.left;
                }
            }
        }
        return out;
    }
}
