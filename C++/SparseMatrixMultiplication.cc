// Given two sparse matrices A and B, return the result of AB.

// You may assume that A's column number is equal to B's row number.

// Example:

// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]

// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]


//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty() || A[0].empty() || B[0].empty())
            return vector<vector<int>>();
        vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int k = 0; k < B.size(); k++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < B[0].size(); j++) {
                        if (B[k][j] != 0)
                            C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return C;
    }
};
