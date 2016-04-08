// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the 
// stock), design an algorithm to find the maximum profit.

public class BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int min = Integer.MAX_VALUE;
        for (int p : prices) {
            min = Math.min(p, min);
            profit = Math.max(profit, p - min);
        }
        return profit;
    }
}
