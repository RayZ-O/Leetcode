// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        vector<int> count(3, 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] > '2' || s[i - 1] < '1') {
                    return 0;
                } else {
                    count[2] = count[0];
                    count[1] = 0;
                }
            } else if (10 * (s[i - 1] - '0') + s[i] - '0' <= 26) {
                count[2] = count[0] + count[1];
            } else {
                count[2] = count[1];
            }
            rotate(count.begin(), count.begin() + 1, count.end());
        }
        return count[1];
    }
};

