// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    string intToRoman(int num) {
        vector<int> ints{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> romans{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string roman;
        for (int i = 12; i >=0; --i) {
            while (num >= ints[i]) {
                roman += romans[i];
                num -= ints[i];
            }
        }
        return roman;
    }
};



