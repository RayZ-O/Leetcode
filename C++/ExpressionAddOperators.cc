// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary
// operators (not unary) +, -, or * between the digits so they evaluate to the target value.

// Examples:
// "123", 6 -> ["1+2+3", "1*2*3"]
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []

class Solution {
    void addOperators(string num, int target, int pos, long tot, long cur, string expr, vector<string>& output) {
        if (pos == num.size()) {
            if (tot + cur == target) {
                output.push_back(expr);
            }
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (num[pos] == '0' && i > pos) {
                break;
            }
            string s = num.substr(pos, i - pos + 1);
            long n = stol(s);
            if (pos == 0) {
                addOperators(num, target, i + 1, 0, n, s, output);
            } else {
                addOperators(num, target, i + 1, tot + cur, n, expr + '+' + s, output);
                addOperators(num, target, i + 1, tot + cur, -n, expr + '-' + s, output);
                addOperators(num, target, i + 1, tot, cur * n, expr + '*' + s, output);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> output;
        addOperators(num, target, 0, 0L, 0L, "", output);
        return output;
    }
};
