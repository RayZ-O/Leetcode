// Write a program to check whether a given number is an ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example,
// 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

// Note that 1 is typically treated as an ugly number.

class Solution {
public:
    bool isUgly(int num) {
        if (num <=0) return false;
        if (num < 7) return true;
        vector<int> factors{2, 3, 5};
        int last;
        do {
            last = num;
            for (int f : factors) {
                if (num % f == 0) {
                    num /= f;
                }
            }
        } while (last > num);
        return num == 1;
    }
};
