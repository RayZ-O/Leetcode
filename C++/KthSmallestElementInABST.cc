// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

class Solution {
    void inorderTraverse(TreeNode* root, int &k, int &val) {
        if (!root || k == 0) return;
        if (root->left) inorderTraverse(root->left, k, val);
        if (--k == 0) {
            val = root->val;
            return;
        }
        if (root->right) inorderTraverse(root->right, k, val);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        inorderTraverse(root, k, val);
        return val;
    }
};


