// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

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

public class SurroundedRegions {
    int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;
    
    public void solve(char[][] board) {
        m = board.length;
        n = m > 0 ? board[0].length : 0;
        for (int i = 0; i < m; i++) {         
            if (board[i][0] == 'O') capture(board, i, 0);
        }
        for (int i = 0; i < m; i++) {
            if (board[i][n-1] == 'O') capture(board, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') capture(board, 0, i);
        }
        for (int i = 0; i < n; i++) {
            if (board[m-1][i] == 'O') capture(board, m-1, i);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    
    void capture(char[][] board, int i, int j) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        board[i][j] = '#';
        while (!q.isEmpty()) {
            int[] b = q.poll();
            for (int[] d : dirs) {
                int x = b[0] + d[0];
                int y = b[1] + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                    board[x][y] = '#';
                    q.add(new int[]{x, y});
                }
            }
        }
    }
}
