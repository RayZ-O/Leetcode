// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following 
// properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

public class SearchA2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) {
            return false;
        }
        int l = 0, h = matrix.length - 1;
        while (l < h) {
            int m = l + (h-l) / 2;
            if (matrix[m][0] <= target) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        if (matrix[h][0] > target && h > 0) h--;
        return Arrays.binarySearch(matrix[h], target) >= 0;
    }
}
