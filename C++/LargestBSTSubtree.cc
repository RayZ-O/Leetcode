// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where
// largest means subtree with largest number of nodes in it.

// Note:
// A subtree must include all of its descendants.
// Here's an example:
//     10
//     / \
//    5  15
//   / \   \
//  1   8   7
// The Largest BST Subtree in this case is the highlighted one.
// The return value is the subtree's size, which is 3.

class Solution {
    struct Info {
        long min;
        long max;
        int count;
        bool valid;
        Info(long x, long y, int c, bool v) : min(x), max(y), count(c), valid(v) {}
    };


    Info largestBSTSubtree(TreeNode* root, int &m) {
        if (!root) {
            return Info(LONG_MAX, LONG_MIN, 0, true);
        }
        auto r1 = largestBSTSubtree(root->left, m);
        auto r2 = largestBSTSubtree(root->right, m);
        if (r1.valid && r2.valid && root->val > r1.max && root->val < r2.min) {
            int c = r1.count + r2.count + 1;
            m = max(m, c);
            int x = min(static_cast<long>(root->val), r1.min);
            int y = max(static_cast<long>(root->val), r2.max);
            return Info(x, y, c, true);
        } else {
            return Info(0, 0, 0, false);
        }

    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int m = 0;
        largestBSTSubtree(root, m);
        return m;
    }
};
