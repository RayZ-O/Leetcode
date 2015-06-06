// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving 
// the order of characters. No two characters may map to the same character but a character 
// may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> dict;
        unordered_map<char, char> map;
        for(int i = 0; i < s.size(); ++i) {
            if (dict.find(s[i]) == dict.end()) {               
                if (map.find(t[i]) != map.end() && map[t[i]] != s[i]) {
                    return false;
                }
                dict.emplace(s[i], t[i]);
                map.emplace(t[i], s[i]);
            } else {
                if (dict[s[i]] != t[i]) return false;
            }          
        }
        return true;
    }
};