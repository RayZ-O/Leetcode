// Given a complete binary tree, count the number of nodes.

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all
// nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive
// at the last level h.

public class CountCompleteTreeNodes {
    int leftHeight(TreeNode root) {
        int h = 0;
        while (root != null) {
            h++;
            root = root.left;
        }
        return h;
    }

    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int lh = leftHeight(root.left);
        int rh = leftHeight(root.right);
        if (lh == rh) {
            return (1 << lh) + countNodes(root.right);
        } else {
            return (1 << rh) + countNodes(root.left);
        }
    }
}
