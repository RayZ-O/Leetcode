// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
    int eval(int x, int y, char op) {
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/': return x / y;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& t : tokens) {
            if (!isdigit(t[0]) && t.size() == 1) {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(eval(x, y, t[0]));
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
