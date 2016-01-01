// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

class Solution {
    TreeNode* prev{nullptr};
    TreeNode* wrong{nullptr};
    TreeNode* cand{nullptr};

    void recover(TreeNode* root) {
        if (!root) {
            return;
        }
        recover(root->left);
        if (prev && prev->val > root->val) {
            if (!wrong) {
                wrong = prev;
                cand = root;
            } else {
                swap(root->val, wrong->val);
                wrong = nullptr;
                return;
            }
        }
        prev = root;
        recover(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        recover(root);
        if (wrong) {
            swap(cand->val, wrong->val);
        }
    }
};
