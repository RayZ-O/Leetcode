// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = “eceba” and k = 2,

// T is "ece" which its length is 3.

public class LongestSubstringWithAtMostKDistinctCharacters {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s.isEmpty() || k < 1) {
            return 0;
        }
        int maxLen = 0;
        Map<Character, Integer> mp = new HashMap<>();
        int curBeg = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            mp.putIfAbsent(c, 0);
            mp.put(c, mp.get(c) + 1);
            while (mp.size() > k) {
                char b = s.charAt(curBeg);
                int cnt = mp.get(b);
                if (cnt == 1) {
                    mp.remove(b);
                } else {
                    mp.put(b, cnt - 1);
                }
                curBeg++;
            }
            maxLen = Math.max(maxLen, i - curBeg + 1);
        }
        return maxLen;
    }
}
