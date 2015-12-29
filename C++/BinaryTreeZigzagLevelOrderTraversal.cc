// Given a binary tree, return the zigzag level order traversal of its nodes' values.
// (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if (!root) {
            return output;
        }
        vector<vector<TreeNode*>> v(2);
        int i = 0;
        v[i].push_back(root);
        while (!v[i].empty()) {
            int j = !i;
            for (auto tn : v[i]) {
                if (tn->left)
                    v[j].push_back(tn->left);
                if (tn->right)
                    v[j].push_back(tn->right);
            }
            vector<int> cur_level(v[i].size());
            if (i) {
                transform(v[i].crbegin(), v[i].crend(), cur_level.begin(), [](TreeNode* tn) {return tn->val;});
            } else {
                transform(v[i].cbegin(), v[i].cend(), cur_level.begin(), [](TreeNode* tn) {return tn->val;});
            }
            output.push_back(cur_level);
            v[i].clear();
            i = j;
        }
        return output;
    }
};
