// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word in
// words exactly once and without any intervening characters.

// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]

// You should return the indices: [0,9].
// (order does not matter).

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> output;
        int len = words[0].size();
        int size = words.size();
        if (size < 1 || len * size > s.size()) {
            return output;
        }
        unordered_map<string, int> dict;
        for (auto& w : words) {
            dict[w]++;
        }
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> mirror;
            int count = 0;
            int cur = i;
            while (cur + len <= s.size()) {
                string t = s.substr(cur, len);
                if (dict.find(t) == dict.end()) {
                    mirror.clear();
                    count = 0;
                } else if (mirror[t] < dict[t]) {
                    mirror[t]++;
                    if (++count == size) {
                        int beg = cur - len * (size - 1);
                        output.push_back(beg);
                        mirror[s.substr(beg, len)]--;
                        count--;
                    }
                } else {
                    string u;
                    int beg = cur - len * count;
                    while ((u = s.substr(beg, len)) != t) {
                        count--;
                        mirror[u]--;
                        beg += len;
                    }
                }
                cur += len;
            }
        }
        return output;
    }
};
