// Implement int sqrt(int x).

// Compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
    	if (x < 0) {
    		return -1;
    	} else if (x == 0) {
    		return 0;
    	} 
    	int low = 1;
    	int high = x;
    	while (low < high) {
    		int mid = low + (high - low) / 2;
    		if (mid < x / mid) {
    			low = mid + 1;
    		} else {
    			high = mid;
    		}
    	}
    	return high <= x / high ? high : high - 1;
    }
};