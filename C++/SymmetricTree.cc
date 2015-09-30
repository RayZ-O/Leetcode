// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3

class Solution {
    bool compare(TreeNode* node1, TreeNode* node2) {
        if (!(node1 || node2)) return true;
        else if (!(node1 && node2)) return false;
        else return node1->val == node2->val &&
                    compare(node1->left, node2->right) &&
                    compare(node2->left, node1->right);

    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
};
