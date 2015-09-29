// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

class Solution {
public:
    void reverseWords(string &s) {
        if (!s.size()) return;
        string res;
        int end = 0;
        bool inWord = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ' && !inWord) {
                end = i;
                inWord = true;
            }
            if (s[i] == ' ' && inWord) {
                res += s.substr(i + 1, end - i) + " ";
                inWord = false;
            }
        }
        if (inWord) res += s.substr(0, end + 1) + " ";
        if (res.size()) res.pop_back();
        s = res;
    }
};
