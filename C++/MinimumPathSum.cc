// Given a m x n grid filled with non-negative numbers, find a path
// from top left to bottom right which minimizes the sum of all numbers
// along its path.

// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int n = grid[0].size();
        vector<int> prev{grid[0][0]};
        vector<int> cur(n, 0);
        for (int i = 1; i < n; i++)
            prev.push_back(prev.back() + grid[0][i]);
        for (int i = 1; i < grid.size(); i++) {
            cur[0] = prev[0] + grid[i][0];
            for (int j = 1; j < n; j++)
                cur[j] = min(cur[j - 1], prev[j]) + grid[i][j];
            swap(prev, cur);
        }
        return prev[n - 1];
    }
};
