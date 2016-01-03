// Remove the minimum number of invalid parentheses in order to make the input string valid.
// Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and ).

// Examples:
// "()())()" -> ["()()()", "(())()"]
// "(a)())()" -> ["(a)()()", "(a())()"]
// ")(" -> [""]

class Solution {
    void getInvalidNums(const string& s, int& left, int& right) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                ++count;
            } else if (c == ')' && --count < 0) {
                right++;
                count = 0;
            }
        }
        left = count;
    }

    void build(string& s, int i, int left, int right, int count, string cur, vector<string>& output) {
        if (left < 0 || right < 0 || count < 0 || i > s.size()) {
            return;
        }

        if (i == s.size()) {
            if (left == 0 && right == 0) {
                output.push_back(cur);
            }
            return;
        }

        if (s[i] == '(') {
            build(s, i + 1, left, right, count + 1, cur + '(', output);
            for (; s[i] == '(' && i < s.size(); i++, left--);
            build(s, i, left, right, count, cur, output);

        } else if (s[i] == ')') {
            build(s, i + 1, left, right, count - 1, cur + ')', output);
            for (; s[i] == ')' && i < s.size(); i++, right--);
            build(s, i, left, right, count, cur, output);
        } else {
            build(s, i + 1, left, right, count, cur + s[i], output);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        getInvalidNums(s, left, right);
        vector<string> output;
        build(s, 0, left, right, 0, "", output);
        return output;
    }
};
