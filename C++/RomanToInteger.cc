// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rtoi{{'I', 1},  {'V', 5},  {'X', 10}, {'L', 50},
                                      {'C', 100}, {'D', 500}, {'M', 1000}};
        int cur = 0;
        int last = 0;
        int num = 0;
        for (auto c : s) {
            cur = rtoi[c];
            if (cur > last) {
                num -= 2 * last;
            }
            num += cur;
            last = cur;
        }
        return num;
    }
};
