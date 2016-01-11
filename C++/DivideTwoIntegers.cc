// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

class Solution {
    const int MAX_INT = numeric_limits<int>::max();
    const int MIN_INT = numeric_limits<int>::min();
    void rmSign(int& num, int& sign) {
        if (num < 0) {
            num = -num;
            sign = -sign;
        }
    }
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return MAX_INT;
        }
        if (dividend == MIN_INT) {
            if (divisor == -1) return MAX_INT;
            else if (divisor == 1) return MIN_INT;
            else if (divisor % 2 == 0) return divide(dividend >> 1, divisor >> 1);
            else return divide(dividend + abs(divisor), divisor) + (divisor > 0 ? -1 : 1);
        }
        if (divisor == MIN_INT) {
            return 0;
        }
        int sign = 1;
        rmSign(dividend, sign);
        rmSign(divisor, sign);
        int res = 0;
        while (dividend > divisor) {
            int count = 1;
            int d = divisor;
            for (; d << 1 < dividend && d << 1 > d; d <<= 1) {
                count <<= 1;
            }
            res += count;
            dividend -= d;
        }
        return sign > 0 ? res : -res;
    }
};
