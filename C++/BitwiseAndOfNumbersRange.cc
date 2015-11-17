// Given a range [m, n] where 0 <= m <= n <= 2147483647, return
// the bitwise AND of all numbers in this range, inclusive.

// For example, given the range [5, 7], you should return 4.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int highest_neq = 0;
        int i = 1;
        for (int l = m, h = n; h; l >>= 1, h >>= 1) {
            if ((l & 1) != (h & 1))
                highest_neq = i;
            i++;
        }
        int mask = ~((1 << highest_neq) - 1);
        return mask & n;
    }
};


