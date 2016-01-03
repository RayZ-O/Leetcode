// Given a string, find the length of the longest substring T that contains at
// most 2 distinct characters.

// For example, Given s = “eceba”,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_set<char> dict;
        char last = 0;
        int substr_beg = 0;
        int consec_beg = 0;
        int max_length = 0;
        for (int i = 0; i < s.size(); i++) {
            if (dict.size() < 2) {
                dict.insert(s[i]);
            } else if (dict.find(s[i]) == dict.end()) {
                max_length = max(max_length, i - substr_beg);
                for_each(dict.begin(), dict.end(), [&](const char c){if(c != last) dict.erase(c);});
                dict.insert(s[i]);
                substr_beg = consec_beg;
            }
            if (s[i] != last) {
                consec_beg = i;
            }
            last = s[i];
        }
        max_length = max(max_length, static_cast<int>(s.size()) - substr_beg);
        return max_length;
    }
};
