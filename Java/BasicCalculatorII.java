// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The 
// integer division should truncate toward zero.

// You may assume that the given expression is always valid.

// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5
// Note: Do not use the eval built-in library function.

public class BasicCalculatorII {
    class StringStream {
        private int i;
        private String s;

        StringStream(String s) {
            i = 0;
            this.s = s;
        }

        boolean hasNext() {
            while (i < s.length() && s.charAt(i) == ' ') i++;
            return i != s.length();
        }

        int nextInt() {
            int num = 0;
            if (hasNext()) {
                while (i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + Character.digit(s.charAt(i++), 10);
                }
            }
            return num;
        }

        char nextChar() {
            return hasNext() ? s.charAt(i++) : (char)-1;
        }
    }

    public int calculate(String s) {
        int res = 0;
        StringStream ss = new StringStream(s);
        int sign = 1;
        int preNum = ss.nextInt();
        while (ss.hasNext()) {
            char op = ss.nextChar();
            switch (op) {
                case '+': case '-':
                    res += sign * preNum;
                    sign = op == '+' ? 1 : -1;
                    preNum = ss.nextInt();
                    break;
                case '*':
                    preNum *= ss.nextInt();
                    break;
                case '/':
                    preNum /= ss.nextInt();
                    break;
            }
        }
        return res + sign * preNum;
    }
}
