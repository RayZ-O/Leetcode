// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

public class GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        List<String> out = new ArrayList<>();
        generate(0, n, new StringBuilder(), out);
        return out;
    }

    void generate(int c, int n, StringBuilder sb, List<String> out) {
        if (n == 0 && c == 0) {
            out.add(sb.toString());
            return;
        }
        if (c > 0) {
            sb.append(')');
            generate(c-1, n, sb, out);
            sb.setLength(sb.length()-1);
        }
        if (n > 0) {
            sb.append('(');
            generate(c+1, n-1, sb, out);
            sb.setLength(sb.length()-1);
        }
    }
}
