// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a
// non-empty substring in str.

// Examples:
// pattern = "abab", str = "redblueredblue" should return true.
// pattern = "aaaa", str = "asdasdasdasd" should return true.
// pattern = "aabb", str = "xyzabcxzyabc" should return false.
// Notes:
// You may assume both pattern and str contains only lowercase letters.

class Solution {
    unordered_set<string> p_set;
    unordered_map<char, string> p_map;
    bool startsWith(string& s, string& t) {
        if (s.size() < t.size()) {
            return false;
        }
        for (int i = 0; i < t.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty() && str.empty()) {
            return true;
        }
        if (pattern.empty() || str.empty()) {
            return false;
        }
        char c = pattern[0];
        if (p_map.find(c) != p_map.end()) {
            string &t = p_map[c];
            return startsWith(str, t) && wordPatternMatch(pattern.substr(1), str.substr(t.size()));
        }
        for (int j = 1; j <= str.size(); j++) {
            string t = str.substr(0, j);
            if (p_set.find(t) == p_set.end()) {
                p_map[c] = t;
                p_set.insert(t);
                if (wordPatternMatch(pattern.substr(1), str.substr(t.size()))) {
                    return true;
                }
                p_map.erase(c);
                p_set.erase(t);
            }
        }
        return false;
    }
};
