// This is a follow up of Shortest Word Distance. The only difference is now you are given the list of 
// words and your method will be called repeatedly many times with different parameters. How would you 
// optimize it?

// Design a class which receives a list of words in the constructor, and implements a method that takes 
// two words word1 and word2 and return the shortest distance between these two words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = "coding", word2 = "practice", return 3.
// Given word1 = "makes", word2 = "coding", return 1.

public class WordDistance {
    Map<String, List<Integer>> mp = new HashMap<>();

    public WordDistance(String[] words) {
        for (int i = 0; i < words.length; i++) {
            mp.putIfAbsent(words[i], new ArrayList<>());
            mp.get(words[i]).add(i);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> is1 = mp.get(word1);
        List<Integer> is2 = mp.get(word2);
        int min = Integer.MAX_VALUE;
        int i = 0, j = 0;
        while (i < is1.size() && j < is2.size()) {
            min = Math.min(min, Math.abs(is1.get(i) - is2.get(j)));
            if (is1.get(i) < is2.get(j)) {
                i++;
            } else {
                j++;
            }
        }
        return min;
    }
}
