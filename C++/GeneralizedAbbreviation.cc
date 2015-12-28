// Write a function to generate the generalized abbreviations of a word.

// Example:
// Given word = "word", return the following list (order does not matter):
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> output;
        int n = 1 << word.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            string cur_str;
            for (int j = 0, mask = i; j < word.size(); j++, mask >>= 1) {
                if (mask & 1) {
                    count++;
                } else {
                    if (0 != count) {
                        cur_str += to_string(count);
                        count = 0;
                    }
                    cur_str += word[j];
                }
            }
            cur_str += count > 0 ? to_string(count) : "";
            output.push_back(cur_str);
        }
        return output;
    }
};
