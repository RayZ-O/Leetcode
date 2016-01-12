// Given a string S and a string T, find the minimum window in S which will contain all the characters in T
// in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum
// window in S.

class Solution {
    const int kIMax = numeric_limits<int>::max();
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> char_map;
        for (char c : t) {
            char_map[c]++;
        }
        int count = t.size();
        int min_win = kIMax;
        int slow = 0, fast = 0;
        int beg = 0;
        while (fast < s.size()) {
            if (char_map.find(s[fast]) != char_map.end() && char_map[s[fast]]-- > 0) {
                count--;
            }
            fast++;
            while (count == 0) {
                if (fast - slow < min_win) {
                    min_win = fast - slow;
                    cout  << min_win << endl;
                    beg = slow;
                }
                if (char_map.find(s[slow]) != char_map.end() && ++char_map[s[slow]] > 0) {
                    count++;
                }
                slow++;
            }
        }
        return min_win == kIMax ? "" : s.substr(beg, min_win);
    }
};
