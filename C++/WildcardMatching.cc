// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int match = 0, next_to = -1;
        int n = p.size();
        while (i < s.size()) {
            if (j < n && p[j] == '*') {
                match = i;
                next_to = ++j;
            } else  if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (next_to > 0) {
                j = next_to;
                i = ++match;
            } else {
                return false;
            }
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
