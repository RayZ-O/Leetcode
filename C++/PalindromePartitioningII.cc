// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n, false));
        vector<int> min_cut(n + 1, 0);
        min_cut[0] = -1;
        for (int i = 1; i < n; i++) {
            p[i][i] = true;
            min_cut[i + 1] = min_cut[i] + 1;
            for (int j = i - 1; j >= 0; j--) {
                if ((j == i - 1 || p[i - 1][j + 1]) && s[j] == s[i]) {
                    p[i][j] = true;
                    min_cut[i + 1] = min(min_cut[i + 1], min_cut[j] + 1);
                }
            }
        }
        return min_cut.back();
    }
};
