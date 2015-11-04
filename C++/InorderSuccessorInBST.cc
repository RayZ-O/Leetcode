// Given a binary search tree and a node in it, find the in-order successor
// of that node in the BST.

// Note: If the given node has no in-order successor in the tree, return null.

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return nullptr;
        TreeNode* node = nullptr;
        if (p->right) {
            node = p->right;
            while (node->left) node = node->left;
            return node;
        }
        while (p != root) {
            if (p->val > root->val)
                root = root->right;
            if (p->val < root->val) {
                node = root;
                root = root->left;
            }
        }
        return node;
    }
};
