// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest 
// means subtree with largest number of nodes in it.

// Note:
// A subtree must include all of its descendants.
// Here's an example:
//     10
//     / \
//    5  15
//   / \   \ 
//  1   8   7
// The Largest BST Subtree in this case is the highlighted one. 
// The return value is the subtree's size, which is 3.

public class LargestBstSubtree {
    class SubTreeInfo {
        int max;
        int min;
        int size;
        SubTreeInfo(int max, int min, int size) {
            this.max = max;
            this.min = min;
            this.size = size;
        }
    }
    
    SubTreeInfo findUntil(TreeNode root) {
        if (root == null) {
            return new SubTreeInfo(Integer.MIN_VALUE, Integer.MAX_VALUE, 0);
        }
        SubTreeInfo l = findUntil(root.left);
        SubTreeInfo r = findUntil(root.right);
        if (root.val < l.max || root.val > r.min) {
            return new SubTreeInfo(Integer.MAX_VALUE, Integer.MIN_VALUE, Math.max(l.size, r.size));
        } else {
           
            return new SubTreeInfo(Math.max(root.val, r.max), Math.min(root.val, l.min), 1 + l.size + r.size);
        }
        
    }
    
    public int largestBSTSubtree(TreeNode root) {
        SubTreeInfo sti = findUntil(root);
        return sti.size;
    }
}
