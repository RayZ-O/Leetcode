// Given a binary tree where all the right nodes are either leaf nodes with a
// sibling (a left node that shares the same parent node) or empty, flip it
// upside down and turn it into a tree where the original right nodes turned
// into left leaf nodes. Return the new root.

// For example:
// Given a binary tree {1,2,3,4,5},
//     1
//    / \
//   2   3
//  / \
// 4   5
// return the root of the binary tree [4,5,2,#,#,3,1].
//    4
//   / \
//  5   2
//     / \
//    3   1

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        vector<TreeNode*> v;
        for (; root; root = root->left;) {
            v.push_back(root);
        }
        for (int i = v.size() - 1; i > 0; i--) {
            v[i]->left = v[i - 1]->right;
            v[i]->right = v[i - 1];
        }
        v[0]->left = v[0]->right = nullptr;
        return v.back();
    }
};
