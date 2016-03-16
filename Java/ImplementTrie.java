// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode {
    TrieNode[] children;
    boolean isEnd;
    // Initialize your data structure here.
    public TrieNode() {
        children = new TrieNode[26];
        isEnd = false;
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode t = root;
        for (int i = 0; i < word.length(); i++) {
            if (t.children[word.charAt(i) - 'a'] == null) {
                t.children[word.charAt(i) - 'a'] = new TrieNode();
            }
            t = t.children[word.charAt(i) - 'a'];
        }
        t.isEnd = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode e = searchNode(word);
        return e != null && e.isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        return searchNode(prefix) != null;
    }

    private TrieNode searchNode(String word) {
        TrieNode t = root;
        for (int i = 0; i < word.length(); i++) {
            if (t.children[word.charAt(i) - 'a'] == null) {
                return null;
            }
            t = t.children[word.charAt(i) - 'a'];
        }
        return t;
    }
}
