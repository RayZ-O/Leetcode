// Given a string containing just the characters '(' and ')', find the length of the longest
// valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which
// has length = 4.

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[st.top()] == '(' && s[i] == ')') {
                st.pop();
            } else {
                st.push(i);
            }
        }
        if (st.empty()) {
            return s.size();
        }
        int low = 0, high = s.size();
        int max_length = 0;
        while (!st.empty()) {
            low = st.top();
            st.pop();
            max_length = max(max_length, high - low - 1);
            high = low;
        }
        max_length = max(max_length, high);
        return max_length;
    }
};
