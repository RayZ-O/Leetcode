// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if
// the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and
// "([)]" are not.

public class ValidParentheses {
    public boolean isValid(String s) {
        Map<Character, Character> mp = new HashMap<>();
        mp.put(')', '(');
        mp.put(']', '[');
        mp.put('}', '{');
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (st.empty() || st.peek() != mp.get(c)) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.isEmpty();
    }
}
