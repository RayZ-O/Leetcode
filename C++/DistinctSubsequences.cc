// Given a string S and a string T, count the number of distinct subsequences of T in S.

// A subsequence of a string is a new string which is formed from the original string by deleting
// some (can be none) of the characters without disturbing the relative positions of the remaining
// characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"

// Return 3.

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> nums(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            nums[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j <= i) {
                    if (s[i-1] != t[j-1]) {
                        nums[i][j] = nums[i-1][j];
                    } else {
                        nums[i][j] = nums[i-1][j] + nums[i-1][j-1];
                    }
                }
            }
        }
        return nums[m][n];
    }
};
