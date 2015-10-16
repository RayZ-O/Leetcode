// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
// struct Point {
//     int x;
//     int y;
//     Point() : x(0), y(0) {}
//     Point(int a, int b) : x(a), y(b) {}
// };

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max_count = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> cos_map;
            int count = 0;
            int duplicate = 0;
            int vertical = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                } else if (points[i].x == points[j].x) {
                    vertical++;
                } else {
                    // avoid overflow
                    double slope = (static_cast<double>(points[i].y) - points[j].y) /
                                 (static_cast<double>(points[i].x) - points[j].x);
                    if (cos_map.find(slope) == cos_map.end())
                        cos_map[slope] = 0;
                    count = max(count, ++cos_map[slope]);
                }
            }
            count = max(count, vertical) + duplicate;
            max_count = max(count, max_count);
        }
        return max_count;
    }
};
