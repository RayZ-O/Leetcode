// Given an input string, reverse the string word by word. A word is defined as a sequence of non-space
// characters.

// The input string does not contain leading or trailing spaces and the words are always separated by a
// single space.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

public class ReverseWordsInAStringII {
    public void reverseWords(char[] s) {
        int n = s.length - 1;
        reverse(s, 0, n);
        int beg = 0;
        for (int i = 0; i <= n; i++) {
            if (s[i] == ' ') {
                reverse(s, beg, i-1);
                beg = i+1;
            }
        }
        reverse(s, beg, n);
    }

    void reverse(char[] s, int i, int j) {
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
}
