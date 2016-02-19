// Given a digit string, return all possible letter combinations that the number could represent.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

public class LetterCombinationsOfAPhoneNumber {
    String chs[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void letterCombinations(String digits, int i, StringBuilder sb, List<String> out) {
        if (i == digits.length()) {
            out.add(sb.toString());
            return;
        }
        for (char c : chs[digits.charAt(i) - '0'].toCharArray()) {
            sb.append(c);
            letterCombinations(digits, i + 1, sb, out);
            sb.setLength(sb.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> out = new ArrayList<>();
        if (!digits.isEmpty()) {
            letterCombinations(digits, 0, new StringBuilder(), out);
        }
        return out;
    }
}
