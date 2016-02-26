// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order 
// of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

public class IsomorphicStrings {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        char[] mp = new char[256];
        boolean[] st = new boolean[256];
        for (int i = 0; i < s.length(); i++) {
            if (mp[s.charAt(i)] == 0) {
                if (st[t.charAt(i)] == true) {
                    return false;
                }
                mp[s.charAt(i)] = t.charAt(i);
                st[t.charAt(i)] = true;
            } else if (mp[s.charAt(i)] != t.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}
