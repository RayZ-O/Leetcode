// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are
// those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

class Solution {
    int m;
    int n;
    const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool exist(vector<vector<char>>& board, int i, int j, string& word, int pos) {
        if (pos == word.size()) {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || word[pos] != board[i][j]) {
            return false;
        }

        board[i][j] = '*';
        bool res = false;
        for (auto d : dirs) {
            if (exist(board, i + d.first, j + d.second, word, pos + 1)) {
                res = true;
                break;
            }
        }
        board[i][j] = word[pos];
        return res;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board.empty() ? 0 : board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
