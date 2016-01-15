// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner
// (row1, col1) and lower right corner (row2, col2).


// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
// Note:
// 1.The matrix is only modifiable by the update function.
// 2.You may assume the number of calls to update and sumRegion function is distributed evenly.
// 3.You may assume that row1 ≤ row2 and col1 ≤ col2.

class NumMatrix {
    vector<vector<int>> binary_indexed_tree;
    vector<vector<int>> &matrix_;

    int getSum2D(int x, int y) {
        x++;
        int sum = 0;
        while (x > 0) {
            sum += getSum1D(x, y);
            x -= x & -x;
        }
        return sum;
    }

    int getSum1D(int x, int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += binary_indexed_tree[x][i];
            i -= i & -i;
        }
        return sum;
    }

    void updateTree2D(int x, int y, int inc) {
        x++;
        while (x < binary_indexed_tree.size()) {
            updateTree1D(x, y, inc);
            x += x & -x;
        }
    }

    void updateTree1D(int x, int i, int inc) {
        i++;
        while (i < binary_indexed_tree[x].size()) {
            binary_indexed_tree[x][i] += inc;
            i += i & -i;
        }
    }
public:
    NumMatrix(vector<vector<int>> &matrix) : matrix_(matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        binary_indexed_tree.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                updateTree2D(i, j, matrix_[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int inc = val - matrix_[row][col];
        matrix_[row][col] = val;
        updateTree2D(row, col, inc);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum2D(row2, col2) - getSum2D(row2, col1 - 1) - getSum2D(row1 - 1, col2) + getSum2D(row1 - 1, col1 - 1);
    }
};
