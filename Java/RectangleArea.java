// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Assume that the total area is never beyond the maximum possible value of int.

public class RectangleArea {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int tot = (C-A)*(D-B) + (G-E)*(H-F);
        int l = Math.max(A, E);
        int r = Math.min(C, G);
        int h = Math.min(D, H);
        int b = Math.max(B, F);
        if (l > r || h < b) {
            return tot;
        }
        return tot - (r-l)*(h-b);
    }
}
