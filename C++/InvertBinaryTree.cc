// Invert a binary tree.

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// to
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

class Solution {
public:
    // 1.recursive
    TreeNode* invertTreer(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            if (root->left) invertTree(root->left);
            if (root->right) invertTree(root->right);
        }
        return root;
    }
    // 2.iterative
    TreeNode* invertTreei(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
};
