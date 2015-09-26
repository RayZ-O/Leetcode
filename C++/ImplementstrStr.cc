// Implement strStr().

// Returns the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.

class Solution {
    vector<int> kmp_table(string needle) {
        int pos = 2;
        int cnd = 0;
        vector<int> table(needle.size(), 0);
        table[0] = -1;
        while (pos < needle.size()) {
            if (needle[pos - 1] == needle[cnd]) {
                cnd++;
            } else if (cnd > 0) {
                cnd = table[pos];
                continue;
            }
            table[pos] = cnd;
            pos++;
        }
        return table;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        vector<int> table = kmp_table(needle);
        int m = 0;
        int i = 0;
        while (m + i < haystack.size()) {
            if (needle[i] == haystack[m + i]) {
                if (i == needle.size() - 1)
                    return m;
                i++;
            } else {
                if (table[i] > -1) {
                    m = m + i - table[i];
                    i = table[i];
                } else {
                    i = 0;
                    m++;
                }
            }
        }
        return -1;
    }
};
