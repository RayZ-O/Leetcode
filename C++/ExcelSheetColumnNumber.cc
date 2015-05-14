// Related to question Excel Sheet Column Title

// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 

class Solution {
public:
    int titleToNumber(string s) {
    	int factor = 1;
    	int number = 0;
        for (auto it = s.crbegin(); it != s.crend(); ++it) {
        	number += factor * (*it - 'A' + 1);
        	factor *= 26;
        }
        return number;
    }
};