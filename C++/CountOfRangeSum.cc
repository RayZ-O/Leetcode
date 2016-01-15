// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.

// Example:
// Given nums = [-2, 5, -1], lower = -2, upper = 2,
// Return 3.
// The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

class Solution {
    struct TreeNode {
        long val;
        TreeNode* left;
        TreeNode* right;
        int count;
        int left_size;
        TreeNode(long v) : val(v), left(nullptr), right(nullptr), count(1), left_size(0) {}
        ~TreeNode() {
            if (left) delete left;
            if (right) delete right;
        }
    };

    void insert(TreeNode* &root, long val) {
        if (!root) {
            root = new TreeNode(val);
        } else if (root->val == val) {
            root->count++;
        } else if (root->val > val) {
            root->left_size++;
            insert(root->left, val);
        } else {
            insert(root->right, val);
        }
    }

    int getLower(TreeNode* root, long val, bool inclusive) {
        if (!root) {
            return 0;
        } else if (root->val == val) {
            return root->left_size + (inclusive ? root->count : 0);
        } else if (root->val > val) {
            return getLower(root->left, val, inclusive);
        } else {
            return root->left_size + root->count + getLower(root->right, val, inclusive);
        }
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long sum = 0;
        int count = 0;
        TreeNode* root = nullptr;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum <= upper && sum >= lower) {
                count++;
            }
            count += getLower(root, sum - lower, true) - getLower(root, sum - upper, false);
            insert(root, sum);
        }
        delete root;
        return count;
    }
};
