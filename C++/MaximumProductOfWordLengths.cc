// Given a string array words, find the maximum value of length(word[i]) * length(word[j])
// where the two words do not share common letters. You may assume that each word will contain
// only lower case letters. If no such two words exist, return 0.

// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".

// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".

// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits;
        for (auto& s: words) {
            bits.push_back(accumulate(s.begin(), s.end(), 0, [](int acc, char c){return acc | 1 << (c - 'a');}));
        }
        int max_length = 0;
        for (int i = 0; i < bits.size(); i++) {
            for (int j = i + 1; j < bits.size(); j++) {
                if (!(bits[i] & bits[j])) {
                    max_length = max(max_length, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return max_length;
    }
};
