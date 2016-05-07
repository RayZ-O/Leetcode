// Write a program to solve a Sudoku puzzle by filling the empty cells.

// Empty cells are indicated by the character '.'.

// You may assume that there will be only one unique solution.

public class SudokuSolver {
    boolean check(char[][] board, int num, int x, int y) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == num + '0' || board[i][y] == num + '0') {
                return false;
            }
        }

        int x_lower = (x / 3) * 3;
        int y_lower = (y / 3) * 3;

        for (int i = x_lower; i < x_lower + 3; i++) {
            for (int j = y_lower; j < y_lower + 3; j++) {
                if (board[i][j] == num + '0') {
                    return false;
                }
            }
        }
        return true;
    }

    boolean solve(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j =0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k < 10; k++) {
                        if (check(board, k, i, j)) {
                            board[i][j] = (char) (k + '0');
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public void solveSudoku(char[][] board) {
        solve(board);
    }
}
