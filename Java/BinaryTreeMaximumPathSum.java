// Given a binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in 
// the tree along the parent-child connections. The path does not need to go through the root.

// For example:
// Given the below binary tree,

//        1
//       / \
//      2   3
// Return 6.

public class BinaryTreeMaximumPathSum {
    int max = Integer.MIN_VALUE;
    
    public int maxPathSum(TreeNode root) {
        getSum(root);
        return max;
    }
    
    int getSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftMax = Math.max(getSum(root.left), 0);
        int rightMax = Math.max(getSum(root.right), 0);
        max = Math.max(max, root.val + leftMax + rightMax);
        return root.val + Math.max(leftMax, rightMax);
    }
}
