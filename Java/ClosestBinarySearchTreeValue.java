// Given a non-empty binary search tree and a target value, find the value in the BST that is closest
// to the target.

// Note:
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.

public class ClosestBinarySearchTreeValue {
    public int closestValue(TreeNode root, double target) {
        if (root == null) {
            return Integer.MIN_VALUE; // assume target greater than 0
        }
         if (root.left == null && root.right == null) {
            return root.val;
        }
        int sub = target < root.val ? closestValue(root.left, target) : closestValue(root.right, target);
        return Math.abs(root.val - target) > Math.abs(sub - target) ? sub : root.val;
    }
}
