// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids.

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        vector<int> cur(n);
        prev[0] = 1;
        for (int i = 0; i < m; i++) {
            cur[0] = obstacleGrid[i][0] ? 0 : prev[0];
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j])
                    cur[j] = 0;
                else
                    cur[j] = cur[j - 1] + prev[j];
            }
            swap(prev, cur);
        }
        return prev.back();
    }
};
