// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
// The integer division should truncate toward zero.

// You may assume that the given expression is always valid.

// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5
// Note: Do not use the eval built-in library function.

class Solution {
    int extractInt(string& s, int& pos) {
        int num = 0;
        for (pos = s.find_first_not_of(' ', pos); pos < s.size() && isdigit(s[pos]); pos++) {
            num = num * 10 + s[pos] - '0';
        }
        pos = s.find_first_not_of(' ', pos);
        return num;
    }
public:
    int calculate(string s) {
        int i = 0;
        long result = 0;
        long cur_result = extractInt(s, i);
        while (i < s.size()) {
            switch (s[i++]) {
                case '+': result += cur_result;
                          cur_result = extractInt(s, i);
                          break;
                case '-': result += cur_result;
                          cur_result = -extractInt(s, i);;
                          break;
                case '*': cur_result *= extractInt(s, i);
                          break;
                case '/': cur_result /= extractInt(s, i);
                          break;
            }
        }
        return result + cur_result;
    }
};
