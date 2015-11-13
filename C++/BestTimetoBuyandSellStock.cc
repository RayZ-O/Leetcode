// Say you have an array for which the ith element is the price of a given
// stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy
// one and sell one share of the stock), design an algorithm to find the
// maximum profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int max_profit = 0;
        int beg_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                max_profit = max(max_profit, prices[i - 1] - beg_price);
                beg_price = min(beg_price, prices[i]);
            }
        }
        return max(max_profit, prices.back() - beg_price);
    }
};
