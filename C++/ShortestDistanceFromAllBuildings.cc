// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
// You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

// Each 0 marks an empty land which you can pass by freely.
// Each 1 marks a building which you cannot pass through.
// Each 2 marks an obstacle which you cannot pass through.
// For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0

// The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
// So return 7.

// Note:
// There will be at least one building. If it is not possible to build such house according to the above rules,
// return -1.

class Solution {
    int m;
    int n;
    const vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int i, int j, int val, vector<vector<int>>& total_dist) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        vector<vector<int>> cur_dist(m, vector<int>(n, 0));
        int min_dist = -1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto& d : dirs) {
                int x = p.first + d.first;
                int y = p.second + d.second;
                if (x >=0 && y >=0 && x < m && y < n && grid[x][y] == val) {
                    grid[x][y]--;
                    cur_dist[x][y] = cur_dist[p.first][p.second] + 1;
                    total_dist[x][y] += cur_dist[x][y];
                    min_dist = min_dist < 0 ? total_dist[x][y] : min(min_dist, total_dist[x][y]);
                    q.emplace(x, y);
                }
            }
        }
        return min_dist;
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = m > 0 ? grid[0].size() : 0;
        int val = 0;
        int min_dist = numeric_limits<int>::max();
        vector<vector<int>> total_dist(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cur_min = bfs(grid, i, j, val--, total_dist);
                    if (cur_min == -1) {
                        return -1;
                    }
                    min_dist = cur_min;
                }
            }
        }
        return min_dist;
    }
};
