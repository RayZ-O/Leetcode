// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Return:

// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
// For the return value, each inner list's elements must follow the lexicographic order.
// All inputs will be in lower-case.

class Solution {
    string sortStr(string str) {
        sort(str.begin(), str.end());
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, int> group_map;
        int group_count = 0;
        sort(strs.begin(), strs.end());
        for (const auto &s : strs) {
            string sorted_s = sortStr(s);
            if (group_map.find(sorted_s) != group_map.end()) {
                output[group_map[sorted_s]].push_back(s);
            } else {
                group_map.emplace(sorted_s, group_count++);
                output.push_back(vector<string>({s}));
            }
        }
        return output;
    }
};
