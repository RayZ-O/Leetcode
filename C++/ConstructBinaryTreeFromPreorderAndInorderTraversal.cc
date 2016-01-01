// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

class Solution {
    using position = pair<int, int>;

    int find(vector<int>& v, int target, position& pos) {
        for (int i = pos.first; i < pos.second; i++) {
            if (v[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* build(vector<int>& preorder, position&& pp, vector<int>& inorder, position&& ip) {
        if (pp.first == pp.second || pp.second - pp.first != ip.second - ip.first) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pp.first]);
        int idx = find(inorder, preorder[pp.first], ip);
        int len = idx - ip.first;
        root->left = build(preorder, {pp.first + 1, pp.first + 1 + len}, inorder, {ip.first, idx});
        root->right = build(preorder, {pp.first + 1 + len, pp.second}, inorder, {idx + 1, ip.second});
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, {0, preorder.size()}, inorder, {0, inorder.size()});
    }
};

