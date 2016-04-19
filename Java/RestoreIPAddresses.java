// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

public class RestoreIPAddresses {
    public List<String> restoreIpAddresses(String s) {
        List<String> out = new ArrayList<>();
        restoreIP(s, 0, 4, new String(), out);
        return out;
    }

    void restoreIP(String s, int i, int c, String cur, List<String> out) {
        if (c == 0) {
            if (i == s.length()) {
                out.add(cur);
            }
        }
        for (int j = i+1; j <= Math.min(i+3, s.length()); j++) {
            if (s.charAt(i) == '0' && j > i+1) {
                break;
            }
            String t = s.substring(i, j);
            if (Integer.parseInt(t) < 256) {
                restoreIP(s, j, c-1, cur + t + (c > 1 ? "." : ""), out);
            }
        }
    }
}
