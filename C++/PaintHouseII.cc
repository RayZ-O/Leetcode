// There are a row of n houses, each house can be painted with one of the k colors. The
// cost of painting each house with a certain color is different. You have to paint all
// the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by a n x k cost
// matrix.
// For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is
// the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint
// all houses.

// Note:
// All costs are positive integers.

class Solution {
    const int kMaxInt = numeric_limits<int>::max();
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        int min_cost = 0;
        int min_cost2 = 0;
        int min_idx = -1;
        for (int i = 0; i < costs.size(); i++) {
            int cur_min = kMaxInt, cur_min2 = kMaxInt;
            int cur_min_idx;
            for (int j = 0; j < costs[0].size(); j++) {
                int cur = costs[i][j] + (j == min_idx ? min_cost2 : min_cost);
                if (cur < cur_min2) {
                    cur_min2 = cur;
                }
                if (cur < cur_min) {
                    swap(cur_min, cur_min2);
                    cur_min_idx = j;
                }
            }
            min_cost = cur_min;
            min_cost2 = cur_min2;
            min_idx = cur_min_idx;
        }
        return min_cost;
    }
};
