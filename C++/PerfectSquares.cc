// Given a positive integer n, find the least number of perfect square numbers
// (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
// return 2 because 13 = 4 + 9.

class Solution {
    bool is_square(int num) {
        int t = static_cast<int>(sqrt(num));
        return t * t == num;
    }
public:
    int numSquares(int n) {
        if (is_square(n)) {
            return 1;
        }
        // Legendre's three-square theorem states that a natural number can be represented as the sum of three
        // squares of integers if and only if n is not of the form n = (8b + 7) * 4^a for integers a and b.
        for (;n % 4 == 0; n /= 4);
        if (n % 8 == 7) {
            return 4;
        }
        for (int i = 1; i <= static_cast<int>(sqrt(n)); i++) {
            if (is_square(n - i * i)) {
                return 2;
            }
        }
        return 3;
    }
};
