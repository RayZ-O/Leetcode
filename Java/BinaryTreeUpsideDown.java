// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node
// that shares the same parent node) or empty, flip it upside down and turn it into a tree where
// the original right nodes turned into left leaf nodes. Return the new root.

// For example:
// Given a binary tree {1,2,3,4,5},
//     1
//    / \
//   2   3
//  / \
// 4   5
// return the root of the binary tree [4,5,2,#,#,3,1].
//    4
//   / \
//  5   2
//     / \
//    3   1

public class BinaryTreeUpsideDown {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        Stack<TreeNode> st = new Stack<>();
        while (root != null) {
            st.push(root);
            root = root.left;
        }
        root = st.peek();
        while (!st.isEmpty()) {
            TreeNode t = st.pop();
            if (!st.isEmpty()) {
                TreeNode n = st.peek();
                t.right = n;
                t.left = n.right;
            } else {
                t.right = null;
                t.left = null;
            }
        }
        return root;
    }

    public TreeNode upsideDownBinaryTreeUtil(TreeNode root) {
        if (root == null || root.left == null) {
            return root;
        }
        TreeNode n = upsideDownBinaryTreeUtil(root.left);
        root.left.right = root;
        root.left.left = root.right;
        root.left = null;
        root.right = null;
        return n;
    }
}
