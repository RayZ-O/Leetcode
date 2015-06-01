// Given an array of integers, every element appears three times except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b0 = 0;
        int b1 = 0;
        for (auto n: nums) {
        	b1 ^= b0 & n; 
        	b0 ^= n;
        	int mask = ~(b0 & b1);
        	b1 &= mask;
        	b0 &= mask;
        }
        return b0;
    }
};