// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as
// shown in the figure.

//             (C, D)                    (G, H)
//    ------------          ------------
//    |          |          |          |
//    ------------          ------------
// (A, B)                 (E, F)

// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.

class Solution {
    int getLength(int p1, int p2, int p3, int p4) {
        if (p2 <= p3 || p4 <= p1) return 0;
        return min(p2, p4) - max(p1, p3);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int totalArea = (C - A) * (D - B) + (G - E) * (H - F);
        int overlap = getLength(A, C, E, G) * getLength(B, D, F, H);
        return totalArea - overlap;
    }
};
