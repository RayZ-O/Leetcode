// There are a row of n houses, each house can be painted with one
// of the three colors: red, blue or green. The cost of painting
// each house with a certain color is different. You have to paint
// all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented
// by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting
// house 0 with color red; costs[1][2] is the cost of painting house 1
// with color green, and so on... Find the minimum cost to paint all houses.

// Note:
// All costs are positive integers.

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;
        vector<int> min_costs;
        for (int c : costs[0])
            min_costs.push_back(c);
        for (int i = 1; i < costs.size(); ++i) {
            int last0 = min_costs[0];
            int last1 = min_costs[1];
            int last2 = min_costs[2];
            min_costs[0] = min(last1, last2) + costs[i][0];
            min_costs[1] = min(last0, last2) + costs[i][1];
            min_costs[2] = min(last0, last1 ) + costs[i][2];
        }
        return *min_element(min_costs.begin(), min_costs.end());
    }
};
