// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An
// island is surrounded by water and is formed by connecting adjacent lands horizontally
// or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:

// 11000
// 11000
// 00100
// 00011
// Answer: 3

class Solution {
    using position = pair<int, int>;
    int m;
    int n;
    const vector<position> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool inGrid(int i, int j) {
        return i >= 0 && i < m && j >=0 && j < n;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<position> q;
        q.emplace(i, j);
        grid[i][j] = '0';
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            for (auto d : dirs) {
                int x = pos.first + d.first;
                int y = pos.second + d.second;
                if (inGrid(x, y) && grid[x][y] == '1') {
                    q.emplace(x, y);
                    grid[x][y] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        n = m > 0 ? grid[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
