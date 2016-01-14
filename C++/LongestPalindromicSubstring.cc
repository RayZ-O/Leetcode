// Given a string S, find the longest palindromic substring in S. You may assume that the
// maximum length of S is 1000, and there exists one unique longest palindromic substring.

class Solution {
    int palindromeLength(string& s, int mid, bool is_gap) {
        int i = is_gap ? mid : mid - 1;
        int j = mid + 1;
        int length = is_gap ? 0 : 1;
        while (i >= 0 && j < s.size() && s[i--] == s[j++]) {
            length += 2;
        }
        return length;
    }

    int palindromeLength(string& s, int mid) {
        return max(palindromeLength(s, mid, false), palindromeLength(s, mid, true));
    }
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int mid = 0;
        for (int i = 0; i < s.size(); i++) {
            int cur_len = palindromeLength(s, i);
            if (longest < cur_len) {
                longest = cur_len;
                mid = i;
            }
        }
        int beg = mid - longest/2 + (longest % 2 ? 0 : 1);
        return s.substr(beg, longest);
    }
};
