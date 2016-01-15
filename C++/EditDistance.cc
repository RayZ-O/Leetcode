// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
// (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// a) Insert a character
// b) Delete a character
// c) Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dist[i][n] = m - i;
        }
        for (int j = 0; j <= n; j++) {
            dist[m][j] = n - j;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dist[i][j] = dist[i+1][j+1];
                } else {
                    dist[i][j] = 1 + min(dist[i+1][j], min(dist[i][j+1], dist[i+1][j+1]));
                }
            }
        }
        return dist[0][0];
    }
};
