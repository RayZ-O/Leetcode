// Determine whether an integer is a palindrome.

public class PalindromeNumber {
    public boolean isPalindrome(int x) {
        int r = 0;
        int y = x;
        while (x > 0) {
            int n = x % 10;
            if ((Integer.MAX_VALUE - n) / 10 < r) {
                return false;
            }
            r = r * 10 + n;
            x /= 10;
        }
        return r == y;
    }
}
