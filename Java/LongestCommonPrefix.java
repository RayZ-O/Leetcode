// Write a function to find the longest common prefix string amongst an array of strings.

public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < strs[0].length(); j++) {
            char c = strs[0].charAt(j);
            for (int i = 1; i < strs.length; i++) {
                if (strs[i].length() <= j || c != strs[i].charAt(j)) {
                    return sb.toString();
                }
            }
            sb.append(c);
        }
        return sb.toString();
    }
}
