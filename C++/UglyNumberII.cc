// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note that 1 is typically treated as an ugly number.

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) {
            return 0;
        }
        vector<int> un(n, 1);
        vector<int> cur{2, 3, 5};
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            un[i] = *min_element(cur.begin(), cur.end());
            if (un[i] == cur[0]) {
                cur[0] = un[++i2] * 2;
            }
            if (un[i] == cur[1]) {
                cur[1] = un[++i3] * 3;
            }
            if (un[i] == cur[2]) {
                cur[2] = un[++i5] * 5;
            }
        }
        return un[n - 1];
    }
};
