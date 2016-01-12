// Given an integer n, count the total number of digit 1 appearing in all non-negative
// integers less than or equal to n.

// For example:
// Given n = 13,
// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }
        long d = 1;
        int count = 0;
        int high = 0, cur = 0, low = 0;
        do {
            high = (n / d) / 10;
            cur = (n / d) % 10;
            switch (cur) {
                case 0: count += high * d;
                        break;
                case 1: low = n % d;
                        count += high * d + low + 1;
                        break;

                default: count += high * d + d;
                         break;
            }
            d *= 10;
        } while (high);
        return count;
    }
};
