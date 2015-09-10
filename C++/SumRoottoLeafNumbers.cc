// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3

// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25. 

class Solution {
    void sumNumbersCollect(TreeNode* node, int cur, int& sum) {
        if (!node->left && !node->right) {
            sum += cur * 10 + node->val;
            return;
        }
        if (node->left) sumNumbersCollect(node->left, cur * 10 + node->val, sum);
        if (node->right) sumNumbersCollect(node->right, cur * 10 + node->val, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root) sumNumbersCollect(root, 0, sum);
        return sum;
    }
};