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

public class WordSearch {
    int dirs[][] = new int[][]{{0,-1}, {0, 1}, {1, 0}, {-1, 0}};

    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    boolean dfs(char[][] board, int x, int y, String word, int idx) {
        if (idx == word.length()) {
            return true;
        }
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] == '.') {
            return false;
        }
        if (board[x][y] != word.charAt(idx)) {
            return false;
        } 
        board[x][y] = '.';
        boolean found = false;
        for (int[] d : dirs) {
            if (dfs(board, x+d[0], y+d[1], word, idx+1)) {
                found = true;
                break;
            }
        }
        board[x][y] = word.charAt(idx);
        return found;
    }
}
