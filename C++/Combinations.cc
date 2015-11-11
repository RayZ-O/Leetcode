// Given two integers n and k, return all possible combinations of k numbers
// out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        if (n <= 0)
            return output;
        if (n < k)
            k = n;
        vector<int> mask(k, 1);
        mask.resize(n, 0);
        do {
            vector<int> v;
            for (int i = 0; i < mask.size(); ++i) {
                if (mask[i])
                    v.push_back(i + 1);
            }
            output.push_back(v);
        } while (prev_permutation(mask.begin(), mask.end()));
    }
};
