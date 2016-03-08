// Given a string, find the length of the longest substring without repeating characters. For example, 
// the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For 
// "bbbbb" the longest substring is "b", with the length of 1.

public class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        int[] mp = new int[256];
        Arrays.fill(mp, -1);
        int max = 0;
        int beg = 0;
        for (int i = 0; i < s.length(); i++) {
            if (mp[s.charAt(i)] != -1) {
                max = Math.max(max, i - beg);
                beg = Math.max(beg, mp[s.charAt(i)] + 1);
            }
            mp[s.charAt(i)] = i;
        }
        return Math.max(max, s.length() - beg);
    }
}
