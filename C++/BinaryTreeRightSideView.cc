// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        TreeNode* node = nullptr;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                node = q.front();
                q.pop()
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            output.push_back(node->val);
        }
        return output;
    }
};
