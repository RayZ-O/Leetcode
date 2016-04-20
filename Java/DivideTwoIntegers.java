// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

public class DivideTwoIntegers {
    public int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return Integer.MAX_VALUE;
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if (divisor == 1) {
            return dividend;
        }

        int sign = (dividend >= 0) ^ (divisor > 0) ? -1 : 1;
        long ldividend = Math.abs((long) dividend);
        long ldivisor = Math.abs((long) divisor);

        int res = 0;

        while (ldividend >= ldivisor) {
            long div = ldivisor;
            int multiple = 1;
            while (div <= ldividend - div) {
                div += div;
                multiple += multiple;
            }
            ldividend -= div;
            res += multiple;
        }

        return res * sign;
    }
}
