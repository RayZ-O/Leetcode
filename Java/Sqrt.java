// Implement int sqrt(int x).

// Compute and return the square root of x.

public class Sqrt {
    public int mySqrt(int x) {
        if (x < 0) {
            return Integer.MIN_VALUE;
        }
        if (x == 0) {
            return 0;
        }
        int l = 1, r = x;
        while (l < r) {
            int mid = l + (r-l) / 2 + 1;
            if (mid <= x / mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
}
