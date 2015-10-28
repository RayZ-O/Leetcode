// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child
// connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// For example,

//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5

// Longest consecutive sequence path is 3-4-5, so return 3.

//    2
//     \
//      3
//     /
//    2
//   /
//  1

// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

class Solution {
    struct NodeLenPair {
        TreeNode* node;
        int length;
    };
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        stack<NodeLenPair> st;
        st.push({root, 1});
        int max_length = 0;
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();
            max_length = max(cur.length, max_length);
            if (cur.node->left) {
                int length = cur.node->left->val == cur.node->val + 1 ? cur.length + 1 : 1;
                st.push({cur.node->left, length});
            }
            if (cur.node->right) {
                int length = cur.node->right->val == cur.node->val + 1 ? cur.length + 1 : 1;
                st.push({cur.node->right, length});
            }
        }
        return max_length;
    }
};
