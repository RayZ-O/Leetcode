// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move
// diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

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

public class LongestIncreasingPathInAMatrix {
    public int longestIncreasingPath(int[][] matrix) {
        int longest = 0;
        int m = matrix.length, n = m > 0 ? matrix[0].length : 0;
        int[][] memo = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (memo[i][j] == 0) {
                    longest = Math.max(longest, dfs(matrix, i, j, m, n, memo));
                }
            }
        }
        return longest;
    }

    int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int[][] matrix, int i, int j, int m, int n, int[][] memo) {
        if (memo[i][j] == 0) {
            memo[i][j] = 1;
            int len = 0;
            for (int[] d : dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    len = Math.max(len, dfs(matrix, x, y, m, n, memo));
                }
            }
            memo[i][j] += len;
        }
        return memo[i][j];
    }
}
