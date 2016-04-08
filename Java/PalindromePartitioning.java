// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

public class PalindromePartitioning {
    public List<List<String>> partition(String s) {
        List<List<String>> out = new ArrayList<>();
        partition(s, 0, new ArrayList<>(), out);
        return out;
    }

    void partition(String s, int i, List<String> cur, List<List<String>> out) {
        if (i == s.length()) {
            out.add(new ArrayList<>(cur));
            return;
        }

        for (int j = i+1; j <= s.length(); j++) {
            String t = s.substring(i, j);
            if (isPalindrome(t)) {
                cur.add(t);
                partition(s, j, cur, out);
                cur.remove(cur.size()-1);
            }
        }
    }

    boolean isPalindrome(String s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--))
                return false;
        }
        return true;
    }
}
