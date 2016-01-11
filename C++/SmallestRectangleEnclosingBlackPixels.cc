// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel.
// The black pixels are connected, i.e., there is only one black region. Pixels are connected
// horizontally and vertically. Given the location (x, y) of one of the black pixels, return
// the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

// For example, given the following image:

// [
//   "0010",
//   "0110",
//   "0100"
// ]
// and x = 0, y = 2,
// Return 6.

class Solution {
    bool oneInRow(vector<char>& v) {
        return any_of(v.begin(), v.end(), [](const char c){return c == '1';});
    }
    bool oneInCol(vector<vector<char>>& vv, int col) {
        return any_of(vv.begin(), vv.end(), [col](const vector<char>& v){return v[col] == '1';});
    }
    int findHorizon(vector<vector<char>>& image, int low, int high, bool lower) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (oneInRow(image[mid]) == lower) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (oneInRow(image[high]) && !lower) high++;
        return high;
    }
    int findVertical(vector<vector<char>>& image, int low, int high, bool lower) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (oneInCol(image, mid) == lower) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (oneInCol(image, high) && !lower) high++;
        return high;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = m > 0 ? image[0].size() : 0;
        int top = findHorizon(image, 0, x, true);
        int bottom = findHorizon(image, x + 1, m - 1, false);
        int left = findVertical(image, 0, y, true);
        int right = findVertical(image, y + 1, n - 1, false);
        return (right - left) * (bottom - top);
    }
};
