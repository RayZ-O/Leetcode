// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of 
// haystack.

public class ImplementStrStr {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }
        int[] pfunc = buildTable(needle);
        int j = 0;
        for (int i = 0; i < haystack.length(); i++) {
            while (j > 0 && haystack.charAt(i) != needle.charAt(j)) {
                j = pfunc[j-1];
            }
            if (haystack.charAt(i) == needle.charAt(j)) {
                j++;
            }
            if (j == needle.length()) {
                return i - j + 1;
            }
        }
        return -1;
    }
    
    int[] buildTable(String needle) {
        int[] pfunc = new int[needle.length()];
        for (int i = 1; i < needle.length(); i++) {
            int j = pfunc[i-1];
            while (j > 0 && needle.charAt(i) != needle.charAt(j)) {
                j = pfunc[j-1];
            }
            if (needle.charAt(i) == needle.charAt(j)) {
                j++;
            }
            pfunc[i] = j;
        }
        return pfunc;
    }
}
