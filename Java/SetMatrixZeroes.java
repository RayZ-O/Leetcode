// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

public class SetMatrixZeroes {
    public void setZeroes(int[][] matrix) {
        if (matrix.length == 0) {
            return;
        }
        int m = matrix.length;
        int n = matrix[0].length;

        boolean zeroCol0 = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                zeroCol0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j > 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (zeroCol0) {
                matrix[i][0] = 0;
            }
        }
    }
}
