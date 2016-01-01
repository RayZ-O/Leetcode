// Given a binary tree, count the number of uni-value subtrees.

// A Uni-value subtree means all nodes of the subtree have the same value.

// For example:
// Given binary tree,
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// return 4.

class Solution {
    bool count(TreeNode* node, int& cnt) {
        if (!node) {
            return true;
        }
        bool left_uniq = count(node->left, cnt);
        bool right_uniq = count(node->right, cnt);

        if (!left_uniq || !right_uniq) {
            return false;
        }

        if (node->left && node->val != node->left->val) {
            return false;
        }
        if (node->right && node->val != node->right->val) {
            return false;
        }
        cnt++;
        return true;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int cnt = 0;
        count(root, cnt);
        return cnt;
    }
};
