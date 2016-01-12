// Given two integers representing the numerator and denominator of a fraction, return
// the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// For example,

// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "";
        }
        string res = numerator != 0 && numerator < 0 ^ denominator < 0 ? "-" : "";
        long n = abs(static_cast<long>(numerator));
        long d = abs(static_cast<long>(denominator));
        res += to_string(n / d);
        long r = n % d;
        if (r == 0) {
            return res;
        }
        res += '.';
        unordered_map<long, long> remainders{{r, res.size()}};
        while (r) {
            n = r * 10;
            res += to_string(n / d);
            r = n % d;
            if (remainders.find(r) != remainders.end()) {
                res = res.insert(remainders[r], "(") + ")";
                break;
            }
            remainders[r] = res.size();
        }
        return res;
    }
};

