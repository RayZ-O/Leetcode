//  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// For example:
// Given the below binary tree and sum = 22,

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1

// return

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

class Solution {
    void pathSumCollect(TreeNode* node, vector<int>& pathElems, int sum, vector<vector<int>>& output) {
        pathElems.push_back(node->val);
        if (!node->left && !node->right && node->val == sum) {
            output.push_back(pathElems);
            pathElems.pop_back();
            return;
        }
        if (node->left) pathSumCollect(node->left, pathElems, sum - node->val, output);
        if (node->right) pathSumCollect(node->right, pathElems, sum - node->val, output);
        pathElems.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> output;
        vector<int> pathElems;
        if (root) pathSumCollect(root, pathElems, sum, output);
        return output;
    }
};
