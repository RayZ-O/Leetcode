// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
    void generate(vector<string> &output, string cur, string &s, int beg, int n) {
        if (beg == s.size() && 4 == n) {
            cur.pop_back();
            output.push_back(cur);
        }
        if (beg + (4 - n) * 3 < s.size() || beg == s.size() || n >= 4) {
            return;
        }
        // 1 digit
        generate(output, cur + s[beg] + '.', s, beg + 1, n + 1);
        // can't have leading 0
        if (s[beg] == '0') {
            return;
        }
        // 2 digits
        if (s.size() >= beg + 2) {
            generate(output, cur + s.substr(beg, 2) + '.', s, beg + 2, n + 1);
        }
        // 3 digits, should be less than 256
        if (s.size() >= beg + 3) {
            string seg = s.substr(beg, 3);
            if (stoi(seg) < 256) {
                generate(output, cur + seg + '.', s, beg + 3, n + 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> output;
        if (s.size() < 4 || s.size() > 12) {
            return output;
        }
        generate(output, "", s, 0, 0);
        return output;
    }
};
