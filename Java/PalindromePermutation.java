// Given a string, determine if a permutation of the string could form a palindrome.

// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.

public class PalindromePermutation {
    public boolean canPermutePalindrome(String s) {
        char[] sa = s.toCharArray();
        int[] c = new int[256];
        for (int i = 0; i < sa.length; i++) {
            c[sa[i]]++;
        }
        int count = 0;
        for (int i :c) {
            if (i % 2 == 1 && ++count > 1) {
                return false;
            }
        }
        return true;
    }
}
