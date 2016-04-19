// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty
// list if no palindromic permutation could be form.

// For example:

// Given s = "aabb", return ["abba", "baab"].

// Given s = "abc", return [].

public class PalindromePermutationII {
    public List<String> generatePalindromes(String s) {
        Map<Character, Integer> mp = new TreeMap<>();
        for (int i = 0; i < s.length(); i++) {
            Integer cnt = mp.get(s.charAt(i));
            if (cnt == null) {
                mp.put(s.charAt(i), 1);
            } else {
                mp.put(s.charAt(i), 1 + cnt);
            }
        }
        String single = "";
        StringBuilder chars = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
            char c = entry.getKey();
            int val = entry.getValue();
            if (val % 2 == 1) {
                if (!single.isEmpty()) {
                    return new ArrayList<>();
                }
                single += c;
            }
            while (val >= 2) {
                chars.append(c);
                val -= 2;
            }
        }
        List<String> out = new ArrayList<>();
        boolean[] used = new boolean[chars.length()];
        generatePalindromes(chars.toString(), used, new StringBuilder(), single, out);
        return out;
    }

    void generatePalindromes(String s, boolean[] used, StringBuilder sb, String single, List<String> out) {
        if (sb.length() == s.length()) {
            out.add(sb.toString()+single+sb.reverse().toString());
            sb.reverse();
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (!used[i]) {
                used[i] = true;
                sb.append(s.charAt(i));
                generatePalindromes(s, used, sb, single, out);
                used[i] = false;
                sb.deleteCharAt(sb.length() - 1);
                while (i+1 < s.length() && s.charAt(i+1) == s.charAt(i)) {
                    i++;
                }
            }
        }
    }
}
