// Given a binary tree, return the vertical order traversal of its nodes' values.
// (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

// Examples:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its vertical order traversal as:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// Given binary tree [3,9,20,4,5,2,7],
//     _3_
//    /   \
//   9    20
//  / \   / \
// 4   5 2   7
// return its vertical order traversal as:
// [
//   [4],
//   [9],
//   [3,5,2],
//   [20],
//   [7]
// ]

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> dict;
        queue<pair<TreeNode*, int>> q;
        if (root) {
            q.emplace(root, 0);
        }
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int distance = q.front().second;
            q.pop();
            dict[distance].push_back(node->val);
            if (node->left) {
                q.emplace(node->left, distance - 1);
            }
            if (node->right) {
                q.emplace(node->right, distance + 1);
            }
        }
        vector<vector<int>> output(dict.size());
        transform(dict.begin(), dict.end(), output.begin(), [](pair<const int, vector<int>>& p){return p.second;});
        return output;
    }
};
