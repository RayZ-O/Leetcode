// You are given an integer array nums and you have to return a new counts array. The counts array has
// the property where counts[i] is the number of smaller elements to the right of nums[i].

// Example:

// Given nums = [5, 2, 6, 1]

// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Return the array [2, 1, 1, 0].

class Solution {
    vector<int> output;

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        int count;
        int left_size;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr), count(1), left_size(0) {}
        ~TreeNode() {
            if (left) delete left;
            if (right) delete right;
        }
    };

    void insert(TreeNode* &root, int val, int i, vector<int>& output, int size) {
        if (!root) {
            root = new TreeNode(val);
            output[i] = size;
        } else if (root->val == val) {
            root->count++;
            output[i] = size + root->left_size;
        } else if (root->val > val) {
            root->left_size++;
            insert(root->left, val, i, output, size);
        } else {
            insert(root->right, val, i, output, size + root->left_size + root->count);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> output(nums.size(), 0);
        TreeNode* root = nullptr;
        for (int i = nums.size() - 1; i >= 0; i--) {
            insert(root, nums[i], i, output, 0);
        }
        delete root;
        return output;
    }
};
