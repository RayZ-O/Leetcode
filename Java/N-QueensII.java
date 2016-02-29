// Follow up for N-Queens problem.

// Now, instead outputting board configurations, return the total number of distinct solutions.

public class N-QueensII {
    int totalNQueens(int row, int n, boolean[] col, boolean[] diag1, boolean[] diag2) {
        if (row == n) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            int x = i + row;
            int y = i - row + n - 1;
            if (!col[i] && !diag1[x] && !diag2[y]) {
                col[i] = diag1[x] = diag2[y] = true;
                count += totalNQueens(row+1, n, col, diag1, diag2);
                col[i] = diag1[x] = diag2[y] = false;
            }
        }
        return count;
    }
    
    public int totalNQueens(int n) {
        boolean[] col = new boolean[n];
        boolean[] diag1 = new boolean[2*n-1];
        boolean[] diag2 = new boolean[2*n-1];
        return totalNQueens(0, n, col, diag1, diag2);
    }
}
