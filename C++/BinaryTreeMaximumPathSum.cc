// Given a binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node
// to any node in the tree along the parent-child connections. The path does not need to
// go through the root.

// For example:
// Given the below binary tree,

//        1
//       / \
//      2   3
// Return 6.

class Solution {
    int maxPathSum(TreeNode* root, int& max_sum) {
        if (!root) {
            return 0;
        }
        int l = max(0, maxPathSum(root->left, max_sum));
        int r = max(0, maxPathSum(root->right, max_sum));
        int sum = root->val + l + r;
        max_sum = max(max_sum, sum);
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = numeric_limites<int>::min();
        maxPathSum(root, max_sum);
        return max_sum;
    }
};
