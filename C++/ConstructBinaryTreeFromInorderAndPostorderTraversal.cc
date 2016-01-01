// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

class Solution {
    using position = pair<int, int>;

    int find(vector<int>& v, int target, position& p) {
        for (int i = p.first; i < p.second; i++) {
            if (v[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* build(vector<int>& inorder, position&& ip, vector<int>& postorder, position&& pp) {
        if (ip.first == ip.second || ip.second - ip.first != pp.second - pp.first) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[pp.second - 1]);
        int idx = find(inorder, postorder[pp.second - 1], ip);
        int len = idx - ip.first;
        root->left = build(inorder, {ip.first, idx}, postorder, {pp.first, pp.first + len});
        root->right = build(inorder, {idx + 1, ip.second}, postorder, {pp.first + len, pp.second - 1});
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, {0, inorder.size()}, postorder, {0, postorder.size()});
    }
};
