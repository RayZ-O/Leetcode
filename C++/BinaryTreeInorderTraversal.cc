// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},

//    1
//     \
//      2
//     /
//    3

// return [1,3,2]. 

class Solution {
    void inorderCollect(TreeNode* root, vector<int>& output) {
        if (root) {
            if (root->left) inorderCollect(root->left, output);
            output.push_back(root->val);
            if (root->right) inorderCollect(root->right, output);
    }
  
 }
public:
    // recursive
    vector<int> inorderTraversalr(TreeNode* root) {
        vector<int> output;
        inorderCollect(root, output);
        return output;
    }
    // iterative
    vector<int> inorderTraversali(TreeNode* root) {
        vector<int> output;
        if (root) {
            stack<TreeNode*> st;
            st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                st.pop();
                if (!node) continue;
                if ((!node->left && !node->right) || !st.empty() && node->right == st.top()) {
                    output.push_back(node->val);
                    continue;
                }
                st.push(node->right);
                st.push(node);
                st.push(node->left);
            }
        }       
        return output;
    }
};

