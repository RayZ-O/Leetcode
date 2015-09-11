// Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
public:
    bool isPalindrome(int x) {
        int t = x / 10;
        int d = 1;
        while (t) {
            t /= 10;
            d *= 10;
        }
        while (d > 1) {
            if ((x / d) % 10 != x % 10) return false;
            x /= 10;
            d /= 100;
        }
        return true;
    }
};
