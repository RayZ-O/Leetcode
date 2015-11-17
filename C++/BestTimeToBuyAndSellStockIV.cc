// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time
// (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (!size)
            return 0;
        if (k >= size / 2) {
            int max_profit = 0;
            for (int i = 1; i < size; i++) {
                max_profit += max(prices[i] - prices[i - 1], 0);
            }
            return max_profit;
        }
        vector<int> prev(size, 0);
        vector<int> cur(size, 0);
        // p[k][i] = max(p[k][i-1], p[k - 1, j] + prices[i] - prices[j])
        for (int i = 0; i < k; i++) {
            int max_diff = prev[0] - prices[0];
            for (int j = 1; j < size; j++) {
                max_diff = max(prev[j] - prices[j], max_diff);
                cur[j] = max(cur[j - 1], prices[j] + max_diff);
            }
            swap(cur, prev);
        }
        return prev.back();
    }
};
