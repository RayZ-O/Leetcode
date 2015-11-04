// Given a binary search tree and a node in it, find the in-order successor
// of that node in the BST.

// Note: If the given node has no in-order successor in the tree, return null.

public class InorderSuccessorInBST {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if (root == null || p == null)
            return null;
        TreeNode node = null;
        if (p.right != null) {
            node = p.right;
            while (node.left != null)
                node = node.left;
        } else {
            while (root != p) {
                if (root.val > p.val) {
                    node = root;
                    root = root.left;
                } else
                    root = root.right;
            }
        }
        return node;
    }
}
