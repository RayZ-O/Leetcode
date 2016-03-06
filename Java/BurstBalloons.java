// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented 
// by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get
// nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the 
// burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note: 
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:

// Given [3, 1, 5, 8]

// Return 167

//     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

public class BurstBalloons {
    int cache[][];
    
    public int maxCoins(int[] nums) {
        int[] cost = new int[nums.length+2];
        cost[0] = cost[cost.length-1] = 1;
        for (int i = 1; i < cost.length-1; i++) {
            cost[i] = nums[i-1];
        }
        cache = new int[cost.length][cost.length];
        for (int[] c : cache) {
            Arrays.fill(c, -1);
        }
        return burst(cost, 0, cost.length-1);
    }

    int burst(int[] cost, int l, int r) {
        if (cache[l][r] != -1) {
            return cache[l][r];
        }
        int coins = 0;
        for (int i = l + 1; i < r; i++) {
            coins = Math.max(coins, cost[l]*cost[i]*cost[r] + burst(cost, l, i) + burst(cost, i, r));
        }
        cache[l][r] = coins;
        return coins;
    }
}
