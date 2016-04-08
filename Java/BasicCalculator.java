// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, 
// non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23
// Note: Do not use the eval built-in library function.

public class Solution {
    public int calculate(String s) {
        Stack<Integer> st = new Stack<>();
        int res = 0;
        int num = 0;
        int op = 1;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case ' ': break;
                case '+':
                    res += num * op;
                    num = 0;
                    op = 1;
                    break;
                case '-':
                    res += num * op;
                    num = 0;
                    op = -1;
                    break;
                case '(':
                    st.push(res);
                    st.push(op);
                    res = 0;
                    op = 1;
                    break;
                case ')':
                    res += num * op;
                    num = 0;
                    res = st.pop() * res + st.pop();
                    break;
                default:
                    num = num * 10 + Character.digit(s.charAt(i), 10);
                    break;
            }
        }
        return res + num * op;
    }
}
