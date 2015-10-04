// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the
// plus + or minus sign -, non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23
// Note: Do not use the eval built-in library function.

class Solution {
    pair<int, int> eval(string s) {
        int res = 0;
        int sign = 1;
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = 10 * num + s[i] - '0';
            } else {
                if (num) {
                    res += num * sign;
                    num = 0;
                }
                if (s[i] == '+')
                    sign = 1;
                else if (s[i] == '-')
                    sign = -1;
                else if (s[i] == ')')
                    return { res, i + 1 };
                else if (s[i] == '(') {
                    auto p = eval(s.substr(i + 1));
                    res += p.first * sign;
                    i += p.second;
                }
            }
        }
        if (num) res += num * sign;
        return { res, 0 };
    }
public:
    int calculate(string s) {
        return eval(s).first;
    }
};
