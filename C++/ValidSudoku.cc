// Determine if a Sudoku is valid.

// The Sudoku board could be partially filled, where empty cells are filled with the
// character '.'.


// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled
// cells need to be validated.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> column(9, 0);
        vector<vector<int>> box(3, {0, 0, 0});
        for (int i = 0; i < 9; i++) {
            int row = 0;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (row & 1 << num || column[j] & 1 << num || box[i/3][j/3] & 1 << num)
                    return false;
                row |= 1 << num;
                column[j] |= 1 << num;
                box[i/3][j/3] |= 1 << num;
            }
        }
        return true;
    }
};
