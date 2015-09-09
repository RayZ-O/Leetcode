//  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such 
//  that adding up all the values along the path equals the given sum.
// For example:
// Given the below binary tree and sum = 22,

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1

// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

class Solution {
    bool pathSum(TreeNode* node, int cur, int sum) {
        if (!node->left && !node->right) return cur == sum? true : false;
        if (node->left && pathSum(node->left, cur + node->left->val, sum)) return true;
        if (node->right) return pathSum(node->right, cur + node->right->val, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root) return pathSum(root, root->val, sum);
        else return false;
    }
};