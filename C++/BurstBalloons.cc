// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
// You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right]
// coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note:
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:

// Given [3, 1, 5, 8]

// Return 167

//     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> ns(nums.size() + 2, 1);
        copy(nums.begin(), nums.end(), ns.begin() + 1);
        int n = ns.size();
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int l = 2; l < n; l++) {
            for (int i = 0; i < n - l; i++) {
                int j = i + l;
                for (int k = i + 1; k < j; k++) {
                    v[i][j] = max(v[i][j], ns[i] * ns[k] * ns[j] + v[i][k] + v[k][j]);
                }
            }
        }
        return v[0][n-1];
    }
};
