// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens
// attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
// both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

class Solution {
    bool isValid(int i, int j, vector<pair<int, int>>& queens) {
        for (auto& p : queens) {
            if (j == p.second || abs(i - p.first) == abs(j - p.second)) {
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>& cur, int row, int count, vector<pair<int, int>>& queens, vector<vector<string>>& output) {
        if (count == 0) {
            output.push_back(cur);
            return;
        }

        for (int j = 0; j < cur[0].size(); j++) {
            if (isValid(row, j, queens)) {
                cur[row][j] = 'Q';
                queens.emplace_back(row, j);
                solve(cur, row + 1, count - 1, queens, output);
                cur[row][j] = '.';
                queens.pop_back();
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        vector<pair<int, int>> queens;
        vector<vector<string>> output;
        solve(cur, 0, n, queens, output);
        return output;
    }
};
