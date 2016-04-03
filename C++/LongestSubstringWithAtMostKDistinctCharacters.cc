// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = “eceba” and k = 2,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k < 1) {
            return 0;
        }
        int beg = 0;
        int n = 0;
        int len = 0;
        vector<int> count(256, 0);
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 0) {
                n++;
                while (n > k) {
                    if (--count[s[beg]] == 0) {
                        n--;
                    }
                    beg++;
                }
            }
            count[s[i]]++;
            len = max(len, i-beg+1);
        }
        return len;
    }
};
