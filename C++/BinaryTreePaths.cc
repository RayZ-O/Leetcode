// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]

class Solution {
    void pathsCollect(TreeNode *node, string cur, vector<string>& output) {
        if (!node->left && !node->right) {
            output.push_back(cur);
            return;
        }
        if (node->left) pathsCollect(node->left, cur + "->" + to_string(node->left->val), output);
        if (node->right) pathsCollect(node->right, cur + "->" + to_string(node->right->val), output);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        if (root) pathsCollect(root, to_string(root->val), output);
        return output;
    }
};
