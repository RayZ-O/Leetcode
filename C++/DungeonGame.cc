// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
// The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially
// positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

// The knight has an initial health point represented by a positive integer. If at any point his health
// point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering
// these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health
// (positive integers).

// In order to reach the princess as quickly as possible, the knight decides to move only rightward or
// downward in each step.

// Write a function to determine the knight's minimum initial health so that he is able to rescue the
// princess.

// Notes:
// 1.The knight's health has no upper bound.
// 2.Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right
// room where the princess is imprisoned.

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = m > 0 ? dungeon[0].size() : 0;
        vector<vector<int>> hp(m + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        hp[m-1][n] = 1;
        for (int i = m - 1; i >= 0; i++) {
            for (int j = n - 1; j >= 0; j++) {
                hp[i][j] = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                if (hp[i][j] <= 0) {
                    hp[i][]] = 1;
                }
            }
        }
        return hp[0][0];
    }
};
