// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

public class ConstructBinaryTreeFromInorderAndPostorderTraversal {
    TreeNode buildTree(int[] inorder, int l1, int r1, int[] postorder, int l2, int r2) {
        if (l1 > r1) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[r2]);
        int i = l1;
        while (inorder[i] != postorder[r2]) i++;
        root.left = buildTree(inorder, l1, i - 1, postorder, l2, l2 + i - l1 - 1);
        root.right = buildTree(inorder, i + 1, r1, postorder, l2 + i - l1, r2 - 1);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }
}
