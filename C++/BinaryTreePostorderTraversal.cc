// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

class Solution {
    // 1.recursively helper
    void postorderCollect(TreeNode* root, vector<int>& output) {
        if (!root) return;
        if(root->left) postorderCollect(root->left, output);
        if(root->right) postorderCollect(root->right, output);
        output.push_back(root->val);
    }

public:
    // 1.recursively
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        postorderCollect(root, output);
        return output;
    }
    // 2. iteratively
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if (root) s1.push(root);
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        vector<int> output;
        while (!s2.empty()) {
            output.push_back(s2.top()->val);
            s2.pop();
        }
        return output;
    }
};
