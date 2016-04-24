// Write a function that takes a string as input and returns the string reversed.

// Example:
// Given s = "hello", return "olleh".

public class ReverseString {
    public String reverseString(String s) {
        char[] sc = s.toCharArray();
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            char temp = sc[i];
            sc[i] = sc[j];
            sc[j] = temp;
        }
        return new String(sc);
    }
}
