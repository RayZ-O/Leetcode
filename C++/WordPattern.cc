// Given a pattern and a string str, find if str follows the same pattern.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// Both pattern and str contains only lowercase alphabetical letters.
// Both pattern and str do not have leading or trailing spaces.
// Each word in str is separated by a single space.
// Each letter in pattern must map to a word with length that is at least 1.

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> patmap;
        unordered_map<string, int> strmap;
        istringstream ss(str);
        for (int i = 0; i < pattern.size(); i++) {
            string word;
            if (ss.eof()) return false;
            ss >> word;
            auto pp = patmap.insert({pattern[i], i});
            auto sp = strmap.insert({word, i});
            if (pp.second ^ sp.second || patmap[pattern[i]] != strmap[word])
                return false;
        }
        return ss.eof();
    }
};
