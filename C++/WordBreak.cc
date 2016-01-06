// Given a string s and a dictionary of words dict, determine if s can be segmented into a
// space-separated sequence of one or more dictionary words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].

// Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> can_break(s.size() + 1, 0);
        can_break[0] = true;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (can_break[j]) {
                    if (wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                        can_break[i + 1] = 1;
                        break;
                    }
                }
            }
        }
        return can_break[s.size()];
    }
};
