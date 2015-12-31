// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        bool fst_row_zero = any_of(matrix[0].begin(), matrix[0].end(), [](int e){return e == 0;});
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for_each(matrix.begin(), matrix.end(), [i](vector<int>& e){e[i] = 0;});
            }
        }
        if (fst_row_zero) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
    }
};
