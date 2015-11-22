// Implement an iterator over a binary search tree (BST). Your iterator will be
// initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
// where h is the height of the tree.

class BSTIterator {
    stack<TreeNode*> nodes;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = nodes.top();
        nodes.pop();
        int smallest = node->val;
        if (node->right) {
            node = node->right;
            nodes.push(node);
            while (node->left) {
                nodes.push(node->left);
                node = node->left;
            }
        }
        return smallest;
    }
};
