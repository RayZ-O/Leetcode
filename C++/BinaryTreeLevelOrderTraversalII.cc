// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

class Solution {
    void levelOrderTraversal(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() <= level) {
            res.push_back({root->val});
        } else {
            res[level].push_back(root->val);
        }
        levelOrderTraversal(root->left, level + 1, res);
        levelOrderTraversal(root->right, level + 1, res);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        levelOrderTraversal(root, 0, output);
        reverse(output.begin(), output.end());
        return output;
    }
};
