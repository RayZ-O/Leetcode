// Given a non-empty binary search tree and a target value, find k values in the BST that are
// closest to the target.

// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to
// the target.

class Solution {
    using max_heap = priority_queue<pair<double, double>>;

    void preorder(TreeNode* node, max_heap& heap, double target, int k) {
        if (!node) {
            return;
        }
        if (heap.size() < k) {
            heap.emplace(abs(target - node->val), node->val);
        } else if (abs(target - node->val) < heap.top().first) {
            heap.pop();
            heap.emplace(abs(target - node->val), node->val);
        }
        preorder(node->left, heap, target, k);
        preorder(node->right, heap, target, k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        max_heap mh;
        preorder(root, mh, target, k);
        vector<int> output;
        while (!mh.empty()) {
            output.push_back(mh.top().second);
            mh.pop();
        }
        return output;
    }
};
