// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (!size)
            return 0;
        vector<int> prev(size, 0);
        vector<int> cur(size, 0);
        for (int i = 0; i < 2; i++) {
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
