// Implement pow(x, n). 

class Solution {
public:
    double myPow(double x, int n) {
		if (n == 0) {
        	return 1;
        } 
        if(n < 0) {
        	x = 1 / x;
        	n = -n;
        }
        double t = myPow(x, n>>1);
        if (n & 1) {
        	return t * t * x;
        } 
        return t * t;
    }
};