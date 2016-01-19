// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

// For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

// Note:
// Because the range might be a large number, the low and high numbers are represented as string.

class Solution {
    const vector<int> pow5{1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125,
                           9765625, 48828125, 244140625, 1220703125};
    const vector<int> greater {4, 3, 3, 3, 3, 3, 2, 2, 1, 0};
    const vector<int> mgreater {2, 1, 1, 1, 1, 1, 1, 1, 0, 0};
    unordered_map<char, char> digits{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    unordered_map<char, char> mdigits{{'0', '0'}, {'1', '1'}, {'8', '8'}};

    int getCount(int n) {
        if (n == 1) {
            return 3;
        }
        return 4 * pow5[n/2-1] * (n % 2 ? 3 : 1);
    }

    string build(string s, int length) {
        if (length < 2) {
            return s;
        }
        string res = s.substr(0, (length + 1) / 2);
        for (int j = length / 2 - 1; j >= 0; j--) {
            res += digits[s[j]];
        }
        return res;
    }

    int getGreater(string s, bool inclusive) {
        int n = s.size();
        int factor = n % 2 ? 3 : 1;
        int count = 0, i;
        for (i = 0; i < n / 2; i++) {
            count += greater[s[i]-'0'] * pow5[n/2-i-1] * factor;
            if (digits.find(s[i]) == digits.end()) {
                break;
            }
        }
        if (i == n / 2) {
            if (n % 2) {
                count += mgreater[s[i]-'0'];
            }
            string strob = build(s, n);
            if (inclusive) {
                count += strob >= s;
            } else {
                count += strob > s;
            }
        }
        return count;
    }

public:
    int strobogrammaticInRange(string low, string high) {
        int ls = low.size(), hs = high.size();
        if (ls > hs) {
            return 0;
        }
        int cnt = 0;
        for (int i = ls + 1; i <= hs; i++) {
            cnt += getCount(i);
        }
        cnt +=  getGreater(low, true) - getGreater(high, false);
        return max(cnt, 0);
    }
};
