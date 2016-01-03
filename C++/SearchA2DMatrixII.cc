// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// For example,

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// Given target = 20, return false.

class Solution {
public:
    // 1. shortest 1336ms
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto upper_it = upper_bound(matrix.begin(),matrix.end(), target, [](int t, vector<int>& v){return t < v[0];});
        return any_of(matrix.begin(), upper_it, [target](vector<int>& v){return binary_search(v.begin(), v.end(), target);});
    }

    // 2. divide and conquer 368 ms
    bool search(vector<vector<int>>& matrix, int left, int top, int right, int bottom, int target) {
        if (left > right || top > bottom) {
            return false;
        }
        if (target < matrix[top][left] || target > matrix[bottom][right]) {
            return false;
        }

        int mid_x = left + (right - left) / 2;
        int mid_y = top + (bottom - top) / 2;
        if (target == matrix[mid_y][mid_x]) {
            return true;
        } else if (target < matrix[mid_y][mid_x]) {
            return search(matrix, left, top, mid_x, mid_y, target)
                || search(matrix, mid_x + 1, top, right, mid_y, target)
                || search(matrix, left, mid_y + 1, mid_x, bottom, target);
        } else {
            return search(matrix, mid_x + 1, top, right, mid_y, target)
                || search(matrix, left, mid_y + 1, mid_x, bottom, target)
                || search(matrix, mid_x + 1, mid_y + 1, right, bottom, target);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return matrix.empty() ? false : search(matrix, 0, 0, matrix[0].size() - 1, matrix.size() - 1, target);
    }

    // 3. iterative walk from right-top conner 280 ms
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix.empty() ? -1 : matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
