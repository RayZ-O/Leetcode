// Given a complete binary tree, count the number of nodes.

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all
// nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive
// at the last level h.

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = 0;
        for (auto n = root; n; n = n->left) {
            l++;
        }
        int r = 0;
        for (auto n = root; n; n = n->right) {
            r++;
        }
        if (l == r) {
            return (1 << l) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
