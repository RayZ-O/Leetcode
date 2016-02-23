// Given a string, determine if it is a palindrome, considering only alphanumeric characters and
// ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

public class ValidPalindrome {
    public boolean isPalindrome(String s) {
        String ls = s.toLowerCase();
        int i = 0, j = ls.length() - 1;
        while (i < j) {
            while (i < j && !Character.isLetterOrDigit(ls.charAt(i))) {
                i++;
            }
            while (i < j && !Character.isLetterOrDigit(ls.charAt(j))) {
                j--;
            }
            if (ls.charAt(i) != ls.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
