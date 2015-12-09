// Given n non-negative integers a1, a2, ..., an, where each represents a
// point at coordinate (i, ai). n vertical lines are drawn such that the
// two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
// together with x-axis forms a container, such that the container contains
// the most water.

// Note: You may not slant the container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        int i = 0, j = height.size() - 1;
        int h1 = height[i], h2 = height[j];
        int max_area = min(h1, h2) * (j - i);
        while (i < j) {
            h1 > h2 ? j-- : i++;
            if (height[j] > h2) {
                max_area = max(min(h1, height[j]) * (j - i), max_area);
                h2 = height[j];
            }
            if (height[i] > h1) {
                max_area = max(min(height[i], h2) * (j - i), max_area);
                h1 = height[i];
            }
        }
        return max_area;
    }
};
