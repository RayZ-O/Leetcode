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
    // recursive
    bool isSymmetricr(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }

    // iterative
    bool isSymmetrici(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root->left);
        st2.push(root->right);
        while (!st1.empty() || !st2.empty()) {
            TreeNode *n1 = st1.top();
            TreeNode *n2 = st2.top();
            if ((!n1 && n2) || (n1 && !n2))
                return false;
            else if (n1 && n2 && n1->val != n2->val)
                return false;
            st1.pop();
            st2.pop();
            if (n1) {
                st1.push(n1->left);
                st1.push(n1->right);
                st2.push(n2->right);
                st2.push(n2->left);
            }
        }
        return st1.empty() && st2.empty();
    }
};
