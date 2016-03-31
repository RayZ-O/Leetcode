// Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the 
// concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

// Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]
// Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

class TrieNode {
    TrieNode[] children;
    int index;
    ArrayList<Integer> indices;
    TrieNode() {
        children = new TrieNode[26];
        index = -1;
        indices = new ArrayList<>();
    }
}

class Trie {
    private TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    void reverse_insert(String word, int wi) {
        TrieNode node = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            int j = word.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new TrieNode();
            }
            node.indices.add(wi);
            node = node.children[j];
        }
        node.index = wi;
    }

    void find_pair(String word, int idx, String[] words, List<List<Integer>> pairs) {
        if (root.index >= 0 && idx != root.index) {
            if (is_palindrome(word)) {
                pairs.add(Arrays.asList(new Integer[]{idx, root.index}));
            }
        }
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            int j = word.charAt(i) - 'a';
            if (node.children[j] == null) return;
            node = node.children[j];
            if (node.index >= 0 && node.index != idx && is_palindrome(word+words[node.index])) {
                pairs.add(Arrays.asList(new Integer[]{idx, node.index}));
            }
        }
        for (int wi : node.indices) {
            if (is_palindrome(word+words[wi])) {
                pairs.add(Arrays.asList(new Integer[]{idx, wi}));
            }
        }
    }

    boolean is_palindrome(String s) {
        for (int i = 0, j = s.length()-1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
    }
}

public class PalindromePairs {
    public List<List<Integer>> palindromePairs(String[] words) {
        Trie trie = new Trie();
        for (int i = 0; i < words.length; i++) {
            trie.reverse_insert(words[i], i);
        }
        List<List<Integer>>  res = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            trie.find_pair(words[i], i, words, res);
        }
        return res;
    }
}
