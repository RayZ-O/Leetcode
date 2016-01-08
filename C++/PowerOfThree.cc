// Given an integer, write a function to determine if it is a power of three.

class Solution {
     const vector<int> pow3{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
public:
    bool isPowerOfThree(int n) {
        return binary_search(pow3.begin(), pow3.end(), n);
    }
};
