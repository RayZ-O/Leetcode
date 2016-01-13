// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all
// ones and return its area.

class Solution {
    void calArea(stack<int>& st, vector<int>& height, int& max_area, int val, int idx) {
        while (!st.empty() && val < height[st.top()]) {
            int t = st.top();
            st.pop();
            int area = height[t] * (st.empty() ? idx : idx - st.top() - 1);
            max_area = max(max_area, area);
        }
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        vector<int> height(n, 0);
        int max_area = 0;
        for (int i = 0; i < m; i++) {
            stack<int> st;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
                calArea(st, height, max_area, height[j], j);
                st.push(j);
            }
            calArea(st, height, max_area, -1, n);
        }
        return max_area;
    }
};
