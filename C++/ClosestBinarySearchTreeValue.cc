// Given a non-empty binary search tree and a target value, find the value in the
// BST that is closest to the target.

// Note:

// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (!root) return -1;
        int closest = root->val;
        double min_diff = abs(root->val - target);
        while(root) {
            double diff = abs(root->val - target);
            if (diff < min_diff) {
                closest = root->val;
                min_diff = diff;
            }
            if (root->val > target) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return closest;
    }
};
