// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally
// or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:

// nums = [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Return 4
// The longest increasing path is [1, 2, 6, 9].

// Example 2:

// nums = [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Return 4
// The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

class Solution {
    const vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m;
    int n;

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& store) {
        if (store[i][j] != 0) {
            return store[i][j];
        }
        int max_len = 1;
        for (auto d : dirs) {
            int x = d.first + i;
            int y = d.second + j;
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
                int len = 1 + dfs(matrix, x, y, store);
                max_len = max(max_len, len);
            }
        }
        store[i][j] = max_len;
        return max_len;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = m > 0 ? matrix[0].size() : 0;
        vector<vector<int>> store(m, vector<int>(n, 0));
        int longest = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j, store);
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
