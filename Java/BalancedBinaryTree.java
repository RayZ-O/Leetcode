// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth
// of the two subtrees of every node never differ by more than 1.

public class BalancedBinaryTree {
    int isHeightBalanced(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = isHeightBalanced(root.left);
        if (l == -1) {
            return -1;
        }
        int r = isHeightBalanced(root.right);
        if (r == -1) {
            return -1;
        }
        return Math.abs(l-r) <= 1 ? Math.max(l, r) + 1 : -1;
    }

    public boolean isBalanced(TreeNode root) {
        return isHeightBalanced(root) != -1;
    }
}
