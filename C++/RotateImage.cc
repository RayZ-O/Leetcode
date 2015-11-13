// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        for (int i = 0; i < n; i++)
           reverse(matrix[i].begin(), matrix[i].end());
    }
};
