// Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int diff = s.size() - t.size();
        if (abs(diff) > 1)
            return false;
        string& longer = diff > 0 ? s : t;
        string& shorter = diff > 0 ? t : s;
        auto iter_pair = mismatch(longer.begin(), longer.end(), shorter.begin());
        if (iter_pair.first == longer.end())
            return diff != 0;
        auto shorter_start = 0 == diff ? iter_pair.second + 1 : iter_pair.second;
        return equal(iter_pair.first + 1, longer.end(), shorter_start);
    }
};
