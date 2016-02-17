// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

public class ReverseInteger {
    public int reverse(int x) {
        int r = 0;
        int sign = Math.abs(x) == x ? 1 : -1;
        x = Math.abs(x);
        while (x != 0) {
            if (Integer.MAX_VALUE / 10 < r || Integer.MAX_VALUE - x % 10 < r * 10) {
                return 0;
            }
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        return r * sign;
    }
}
