// A strobogrammatic number is a number that looks the same when rotated 180 degrees
// (looked at upside down).

// Find all strobogrammatic numbers that are of length = n.

// For example,
// Given n = 2, return ["11","69","88","96"].

class Solution {
    typedef unordered_map<char, char> StrobMap;
    void collectStrobogrammatic(int n, string cur, vector<string>& output, StrobMap& strobMap) {
        if (!n) {
            output.push_back(cur);
            return;
        }
        for (auto cp : strobMap) {
            if (n == 2 && cp.first == '0') continue;
            collectStrobogrammatic(n - 2, cp.first + cur + cp.second, output, strobMap);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        StrobMap strobMap{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        vector<string> midnum{"0", "1", "8"};
        vector<string> output;
        if (n % 2 == 0) {
            collectStrobogrammatic(n, "", output, strobMap);
        } else {
            for (auto s : midnum) {
                collectStrobogrammatic(n - 1, s, output, strobMap);
            }
        }
        return output;
    }
};
