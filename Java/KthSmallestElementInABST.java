// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

public class KthSmallestElementInABST {
    int i = 0;
    public int kthSmallest(TreeNode root, int k) {
        if (root == null) {
            return -1;
        }
        int l = kthSmallest(root.left, k);
        if (l != -1) return l;
        if (k == ++i) {
            return root.val;
        }
        int r = kthSmallest(root.right, k);
        if (r != -1) return r;
        return -1;
    }
}
