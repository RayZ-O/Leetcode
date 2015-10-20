// Given n pairs of parentheses, write a function to generate all combinations of
// well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

class Solution {
    void generate(int n, int m, string cur, vector<string>& output) {
        if (n > 0) generate(n - 1, m + 1, cur + '(', output);
        if (m > 0) generate(n, m - 1, cur + ')', output);
        if (0 == m && 0 ==n)  output.push_back(cur);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        generate(n, 0, "", output);
        return output;
    }
};
