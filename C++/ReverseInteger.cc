// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321 

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0 && rev < 99999999 && rev > -99999999) {
            rev *= 10;
            rev += x % 10;
            x /= 10;          
        } 
        if(x) {
            while (x != 0) {
                int temp = rev * 10;
                if (temp/10 != rev) {
                    return 0;
                }
                rev = temp;
                temp = rev + x % 10;
                if (temp - x % 10 != rev) {
                    return 0;
                }
                rev = temp;
                x /= 10; 
            }
        }
        return rev;
    }
};