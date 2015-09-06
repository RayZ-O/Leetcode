// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int max_len = 0;
        unordered_map<char, int> charToPosMap;
        for (int i = 0; i < s.size(); ++i) {                   
            auto it = charToPosMap.find(s[i]);
            if(it != charToPosMap.end() && i - it->second <= len) {
                if (len > max_len) max_len = len;
                len = i - it->second;
            } else {
                len++;
            }
            charToPosMap[s[i]] = i;
        }
        if (len > max_len) max_len = len;
        return max_len;
    }
};
