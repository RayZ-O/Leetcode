// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

class Solution {
    TreeNode* prev{nullptr};
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
