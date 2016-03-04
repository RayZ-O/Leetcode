// Write a function to generate the generalized abbreviations of a word.

// Example:
// Given word = "word", return the following list (order does not matter):
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", 
// "2r1", "3d", "w3", "4"]

public class GeneralizedAbbreviation {
    public List<String> generateAbbreviations(String word) {
        List<String> out = new ArrayList<>();
        generate(word, 0, new StringBuilder(), out);
        return out;
    }

    void generate(String word, int idx, StringBuilder sb, List<String> out) {
        if (idx >= word.length()) {
            out.add(sb.toString());
            return;
        }
        for (int i = idx; i <= word.length(); i++) {
            int len = sb.length();
            int w = i - idx;
            if (w > 0) {
                sb.append(w);
            }
            if (i < word.length()) {
                sb.append(word.charAt(i));
            }
            generate(word, i + 1, sb, out);
            sb.setLength(len);
        }
    }
}
