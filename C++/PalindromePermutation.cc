// Given a string, determine if a permutation of the string could form a palindrome.

// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> char_table;
        for (char c : s) {
            auto pair = char_table.emplace(c, 1);
            if (!pair.second) char_table[c]++;
        }
        bool single = s.size() % 2 == 0 ? true : false;
        for (auto p : char_table) {
            if (p.second % 2 != 0) {
                if (single) return false;
                else single = true;
            }
        }
        return true;
    }
};
