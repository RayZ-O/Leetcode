// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

public class RecoverBinarySearchTree {
    TreeNode prev = null;
    TreeNode n1 = null;
    TreeNode n2 = null;

    public void recoverTree(TreeNode root) {
        findWrongNode(root);
        if (n1 != null || n2 != null) {
            int temp = n1.val;
            n1.val = n2.val;
            n2.val = temp;
        }
    }

    void findWrongNode(TreeNode node) {
        if (node == null) {
            return;
        }

        findWrongNode(node.left);
        
        if (prev != null && prev.val > node.val){
            if (n1 == null) {
                n1 = prev;
            }
            n2 = node;
        }
        prev = node;
        
        findWrongNode(node.right);
    }
}
