// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like
// (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before
// you buy again).

// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> s(3, vector<int>(n, 0));
        s[1][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            s[0][i] = max(s[2][i-1], s[0][i-1]);             // rest
            s[1][i] = max(s[0][i-1] - prices[i], s[1][i-1]); // buy
            s[2][i] = s[1][i-1] + prices[i];                 // sell
        }
        return max(s[2][n-1], s[0][n-1]);
    }
};
