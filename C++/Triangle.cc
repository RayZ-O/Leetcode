// Given a triangle, find the minimum path sum from top to bottom.
// Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11
// (i.e., 2 + 3 + 5 + 1 = 11).

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        vector<int> prev(triangle.size(), 0);
        prev[0] = triangle[0][0];
        vector<int> cur(triangle.size(), 0);
        for (int i = 1; i < triangle.size(); i++) {
            cur[0] = prev[0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                cur[j] = min(prev[j], prev[j - 1]) + triangle[i][j];
            }
            cur[i] = prev[i - 1] + triangle[i][i];
            swap(cur, prev);
        }
        return *min_element(prev.begin(), prev.end());
    }
};
