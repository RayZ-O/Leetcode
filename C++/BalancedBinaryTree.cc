// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary
// tree in which the depth of the two subtrees of every node never differ
// by more than 1

class Solution {
public:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
