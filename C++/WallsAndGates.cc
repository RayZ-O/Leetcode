// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent
// INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach
// a gate, it should be filled with INF.

// For example, given the 2D grid:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

class Solution {
    struct Point {
        int x;
        int y;
        Point(int i, int j) : x(i), y(j) {}
    };
    int row_size;
    int col_size;

    bool inGrid(int i, int j) {
        return i >= 0 && j >= 0 && i < col_size && j < row_size;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty())
            return;

        stack<Point> gates;
        col_size = rooms.size();
        row_size = rooms[0].size();
        for (int i = 0; i < col_size; i++) {
            for (int j = 0; j < row_size; j++) {
                if (rooms[i][j] == 0)
                    gates.emplace(i, j);
            }
        }

        vector<Point> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<Point> bfs_queue;
        while (!gates.empty()) {
            Point p = gates.top();
            gates.pop();
            bfs_queue.push(p);
            while (!bfs_queue.empty()) {
                Point cur = bfs_queue.front();
                bfs_queue.pop();
                for (auto d : dirs) {
                    int x = cur.x + d.x;
                    int y = cur.y + d.y;
                    int distance = rooms[cur.x][cur.y] + 1;
                    if (inGrid(x, y) && rooms[x][y] > distance) {
                        rooms[x][y] = distance;
                        bfs_queue.emplace(x, y);
                    }
                }
            }
        }
    }
};
