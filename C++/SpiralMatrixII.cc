// Given an integer n, generate a square matrix filled with elements
// from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n, vector<int>(n, 0));
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int elem = 1;
        int i = 0;
        int j = -1;
        int d = 0;
        int count = 0;
        while (n > 0) {
            i += dirs[d][0];
            j += dirs[d][1];
            output[i][j] = elem++;
            count++;
            if (count == n) {
                d = (d + 1) % 4;
                n -= d % 2;
                count = 0;
            }
        }
        return output;
    }
};
