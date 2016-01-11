// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is freedom by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
    const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;

    bool inBoard(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        return true;
    }

    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        board[i][j] = 'F';
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto& d : dirs) {
                int x = p.first + d.first;
                int y = p.second + d.second;
                if (inBoard(x, y) && board[x][y] == 'O') {
                    board[x][y] = 'F';
                    q.emplace(x, y);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = m > 0 ? board[0].size() : 0;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                bfs(board, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                bfs(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'F') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
