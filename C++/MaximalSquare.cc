// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all
// 1's and return its area.

// For example, given the following matrix:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        vector<vector<int>> sqr(m + 1, vector<int>(n + 1, 0));
        int max_len = 0;
        for (int i = 1 ; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    sqr[i][j] = min(sqr[i][j-1], min(sqr[i-1][j], sqr[i-1][j-1])) + 1;
                    max_len = max(max_len, sqr[i][j]);
                } else {
                    sqr[i][j] = 0;
                }
            }
        }
        return max_len * max_len;
    }
};
