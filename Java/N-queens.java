// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens 
// attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both 
// indicate a queen and an empty space respectively.

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

public class N-queens {
    List<String> buildBoard(char[][] board) {
        List<String> ls = new ArrayList<>();
        for (char[] row : board) {
            ls.add(new String(row));
        }
        return ls;
    }
    
    boolean isValid(char[][] board, int row, int col) {
        for (int i = 0; i < board.length; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    void solveNQueens(char[][] board, int row, List<List<String>> out) {
            if (row == board.length) {
                out.add(buildBoard(board));
                return;
            }
            for (int j = 0; j < board.length; j++) {
                if (isValid(board, row, j)) {
                    board[row][j] = 'Q';
                    solveNQueens(board, row + 1, out);
                    board[row][j] = '.';
                }
            }
        }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> out = new ArrayList<>();
        char[][] board = new char[n][n];
        for (int i = 0; i < board.length; i++) {
            Arrays.fill(board[i], '.');
        }
        solveNQueens(board, 0, out);
        return out;
    }
}
