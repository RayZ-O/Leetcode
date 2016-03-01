// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be 
// validated.

public class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        boolean[] row = new boolean[10];
        boolean[] col = new boolean[10];
        boolean[] box = new boolean[10];
        for (int i = 0; i < 9; i++) {
            Arrays.fill(row, false);
            Arrays.fill(col, false);
            Arrays.fill(box, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' ) {
                    if (row[board[i][j]-'0']) {
                        return false;
                    }
                    row[board[i][j]-'0'] = true;
                }
                if (board[j][i] != '.') {
                    if (col[board[j][i]-'0']) {
                        return false;
                    }
                    col[board[j][i]-'0'] = true;
                }
                
                int r = (i/3)*3 + j/3, c = (i%3)*3 + j%3;
                if (board[r][c] != '.') {
                    if (box[board[r][c]-'0']) {
                        return false;
                    }
                    box[board[r][c]-'0'] = true;
                }
            }
        }
        return true;
    }
}
