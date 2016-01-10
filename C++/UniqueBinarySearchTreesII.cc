// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
    vector<TreeNode*> generate(int beg, int end) {
        if (beg > end) {
            return vector<TreeNode*>{nullptr};
        }
        if (beg == end) {
            return vector<TreeNode*>{new TreeNode(beg)};
        }
        vector<TreeNode*> output;
        for (int i = beg; i <= end; i++) {
            for (auto l : generate(beg, i - 1)) {
                for (auto r : generate(i + 1, end)) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    output.push_back(root);
                }
            }
        }
        return output;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return vector<TreeNode*>();
        }
        return generate(1, n);
    }
};
