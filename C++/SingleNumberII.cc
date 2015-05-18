#include "test.h"

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

int main() {
	vector<int> v{1,1,1,2,2,2,3,3,3,4,4,4,4,4};
	Solution s;
	cout << s.singleNumber(v) << endl;
}