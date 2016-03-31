// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word 
// is a valid dictionary word.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].

// A solution is ["cats and dog", "cat sand dog"].

public class WordBreakII {
    public List<String> wordBreak(String s, Set<String> wordDict) {
        List<String>[] memo = new ArrayList[s.length()+1];
        memo[s.length()] = new ArrayList<String>(){{add("");}};
        return wordBreak(s, 0, wordDict, memo);
    }

    List<String> wordBreak(String s, int beg, Set<String> wordDict, List<String>[] memo) {
        if (memo[beg] == null) {
            List<String> res = new ArrayList<>();
            for (int i = beg + 1; i <= s.length(); i++) {
                if (wordDict.contains(s.substring(beg, i))) {
                    for (String t : wordBreak(s, i, wordDict, memo)) {
                        res.add(s.substring(beg, i) + (t.isEmpty() ? t : " " + t));
                    }
                }
            }
            memo[beg] = res;
        }
        return memo[beg];
    }
}
