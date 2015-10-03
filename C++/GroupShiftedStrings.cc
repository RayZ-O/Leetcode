// Given a string, we can "shift" each of its letter to its successive letter,
// for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"

// Given a list of strings which contains only lowercase alphabets, group all strings
// that belong to the same shifting sequence.

// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Return:

// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
// Note: For the return value, each inner list's elements must follow the lexicographic order.

class Solution {
    string shift(const string& s) {
        string res;
        for (char c : s) {
            int dif = c - s[0];
            res += 'a' + (dif >= 0 ? dif : dif + 26);
        }
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> output;
        unordered_map<string, int> str_idx_map;
        int idx = 0;
        for (const auto s : strings) {
            string res = shift(s);
            auto p = str_idx_map.find(res);
            if (p == str_idx_map.end()) {
                output.push_back({s});
                str_idx_map.insert({res, idx});
                idx++;
            } else {
                output[p->second].push_back(s);
            }
        }
        for (auto &vs : output) {
            sort(vs.begin(), vs.end());
        }
        return output;
    }
};
