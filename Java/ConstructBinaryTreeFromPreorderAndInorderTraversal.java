// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    TreeNode buildTree(int[] preorder, int l1, int r1, int[] inorder, int l2, int r2) {
        if (l1 > r1) {
            return null;
        }    
        TreeNode root = new TreeNode(preorder[l1]);
        int i = l2;
        while (inorder[i] != preorder[l1]) 
            i++;
        root.left = buildTree(preorder, l1 + 1, l1 + i - l2, inorder, l2, i - 1);
        root.right = buildTree(preorder, l1 + i - l2 + 1, r1, inorder, i + 1, r2);
        return root;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);   
    }
}
