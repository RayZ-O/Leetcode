// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> v(m + 1, vector<bool>(n + 1, false));
        v[0][0] = true;
        for (int i = 1; i <= m; i++) {
            if (v[i-1][0] && s1[i-1] == s3[i-1]) {
                v[i][0] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (v[0][i-1] && s2[i-1] == s3[i-1]) {
                v[0][i] = true;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                v[i][j] = v[i-1][j] && s1[i-1] == s3[i+j-1] || v[i][j-1] && s2[j-1] == s3[i+j-1];
            }
        }
        return v[m][n];
    }
};
