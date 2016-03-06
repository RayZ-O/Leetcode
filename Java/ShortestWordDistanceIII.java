// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as 
// word2.

// Given a list of words and two words word1 and word2, return the shortest distance between these two words 
// in the list.

// word1 and word2 may be the same and they represent two individual words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.

// Note:
// You may assume word1 and word2 are both in the list.

public class ShortestWordDistanceIII {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            if (word1.equals(words[i])) {
                l1.add(i);
            }
            if (word2.equals(words[i])) {
                l2.add(i);
            }
        }
        int i = 0, j = 0;
        int min = Integer.MAX_VALUE;
        while (i < l1.size() && j < l2.size()) {
            if (l1.get(i) - l2.get(j) != 0) {
                min = Math.min(min, Math.abs(l1.get(i) - l2.get(j)));
            }
            if (l1.get(i) < l2.get(j)) i++;
            else j++;
        }
        return min;
    }
}
