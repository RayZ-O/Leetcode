// Given n non-negative integers representing the histogram's bar height where the
// width of each bar is 1, find the area of largest rectangle in the histogram

// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

class Solution {
    void update(int i, vector<int>& height, stack<int>& st, int& largest) {
        int t = st.top();
        st.pop();
        int area = height[t] * (st.empty() ? i : i - st.top() - 1);
        largest = max(largest, area);
    }
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;
        int largest = 0;
        int i = 0;
        while (i < height.size()) {
            if (st.empty() || height[i] >= height[st.top()]) {
                st.push(i++);
            } else {
                update(i, height, st, largest);
            }
        }
        while (!st.empty()) {
            update(i, height, st, largest);
        }
        return largest;
    }
};
