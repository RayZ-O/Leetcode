// Follow up for N-Queens problem.

// Now, instead outputting board configurations, return the total number of distinct solutions.

class Solution {
    bool isValid(int i, int j, vector<pair<int, int>>& queens) {
        for (auto& p : queens) {
            if (j == p.second || abs(i - p.first) == abs(j - p.second)) {
                return false;
            }
        }
        return true;
    }
    void solve(int row, int n, int& count, vector<pair<int, int>>& queens) {
        if (row == n) {
            count++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isValid(row, j, queens)) {
                queens.emplace_back(row, j);
                solve(row + 1, n, count, queens);
                queens.pop_back();
            }
        }
    }
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<pair<int, int>> queens;
        solve(0, n, count, queens);
        return count;
    }
};
