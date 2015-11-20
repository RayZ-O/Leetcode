// Given a matrix of m x n elements (m rows, n columns), return all elements
// of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if (matrix.empty()) {
            return output;
        }
        int ibeg = 0;
        int iend = matrix.size() - 1;
        int jbeg = 0;
        int jend = matrix[0].size() - 1;
        while (ibeg <= iend && jbeg <= jend) {
            for (int j = jbeg; j <= jend; j++) {
                output.push_back(matrix[ibeg][j]);
            }
            if(iend < ++ibeg) break;

            for (int i = ibeg; i <= iend; i++) {
                output.push_back(matrix[i][jend]);
            }
            if(--jend < jbeg) break;

            for (int j = jend; j >= jbeg; j--) {
                output.push_back(matrix[iend][j]);
            }
            iend--;

            for (int i = iend; i >= ibeg; i--) {
                output.push_back(matrix[i][jbeg]);
            }
            jbeg++;
        }
        return output;
    }
};
