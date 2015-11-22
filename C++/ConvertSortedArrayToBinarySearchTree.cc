// Given an array where elements are sorted in ascending order,
// convert it to a height balanced BST.

class Solution {
    TreeNode* buildBST(vector<int>::iterator beg, vector<int>::iterator end) {
        if (beg >= end) {
            return nullptr;
        }
        int length = end - beg;
        auto mid = beg + length / 2;
        TreeNode* root = new TreeNode(*mid);
        root->left = buildBST(beg, mid);
        root->right = buildBST(mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums.begin(), nums.end());
    }
};
