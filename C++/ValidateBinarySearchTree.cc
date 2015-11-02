// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a root contains only roots with keys less than the root's key.
// The right subtree of a root contains only roots with keys greater than the root's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
    TreeNode* prev{nullptr};
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        return isValidBST(root->right);
    }
};
