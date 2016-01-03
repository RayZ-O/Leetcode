// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a
// cellular automaton devised by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each
// cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following
// four rules (taken from the above Wikipedia article):

// 1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// 2.Any live cell with two or three live neighbors lives on to the next generation.
// 3.Any live cell with more than three live neighbors dies, as if by over-population..
// 4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.

class Solution {
    int m;
    int n;

    const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    bool inBoard(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void update(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        for (const auto& d : dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if (inBoard(x, y) && board[x][y] > 0) {
                count++;
            }
        }
        if (board[i][j] == 1 && (count < 2 || count > 3)) {
            board[i][j] = 2;
        } else if (board[i][j] == 0 && count == 3) {
            board[i][j] = -1;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = m > 0 ? board[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(board, i, j);
            }
        }
        for (auto& b : board) {
            for (int& i : b) {
                if (i == 2)       i = 0;
                else if (i == -1) i = 1;
            }
        }
    }
};
