// This is a follow up of Shortest Word Distance. The only difference is now
// you are given the list of words and your method will be called repeatedly
// many times with different parameters. How would you optimize it?

// Design a class which receives a list of words in the constructor, and implements
// a method that takes two words word1 and word2 and return the shortest distance
// between these two words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

public class ShortestWordDistanceII {
    private HashMap<String, ArrayList<Integer>> wordToIndex = new HashMap<>();

    public WordDistance(String[] words) {
        for (int i = 0; i < words.length; i++) {
            ArrayList<Integer> idxs = wordToIndex.get(words[i]);
            if (idxs == null) {
                wordToIndex.put(words[i], new ArrayList<Integer>(Arrays.asList(i)));
            } else {
                idxs.add(i);
            }
        }
    }

    public int shortest(String word1, String word2) {
        ArrayList<Integer> l1 = wordToIndex.get(word1);
        ArrayList<Integer> l2 = wordToIndex.get(word2);
        int min = Math.abs(l1.get(0) - l2.get(0));
        for (int i = 0, j = 0; i < l1.size() && j < l2.size(); ) {
            min = Math.min(min, Math.abs(l1.get(i) - l2.get(j)));
            if (l1.get(i) > l2.get(j))
                j++;
            else
                i++;
        }
        return min;
    }
}

