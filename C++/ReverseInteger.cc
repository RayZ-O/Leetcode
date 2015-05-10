// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321 


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        while (x != 0) {
            int digit = x % 10;
            if ((INT_MAX - digit) / 10 < rev) {
                return 0;
            }
            rev = rev * 10 + digit;
            x /= 10;          
        }     
        return sign * rev;
    }
};

