// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
// Find and return the shortest palindrome you can find by performing this transformation.

// For example:

// Given "aacecaaa", return "aaacecaaa".

// Given "abcd", return "dcbabcd".

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string st = s + '#' + t;
        vector<int> table(st.size(), 0);
        for (int i = 1; i < st.size(); i++) {
            int len = table[i-1];
            while (len > 0 && st[i] != st[len]) {
                len = table[len-1];
            }
            table[i] = st[i] == st[len] ? len + 1 : 0;
        }
        return t + s.substr(table[st.size()-1]);
    }
};
