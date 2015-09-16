// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode { 
public:
    unordered_map<char, TrieNode*> chars;  // for branch node
    bool isEnd;                            // for element node
    TrieNode() : chars(), isEnd(false) { }
};

class Trie {
    bool isPrefix(string word, TrieNode* &node) {
         for (int i = 0; i < word.size(); i++) {
            if(node->chars.find(word[i]) == node->chars.end()) {
                return false;
            }
            node = node->chars[word[i]];
        }
        return true;
    }
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if(node->chars.find(word[i]) == node->chars.end()) {
                node->chars.emplace(word[i], new TrieNode());
            } 
            node = node->chars[word[i]];
        }
        node->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        if (!isPrefix(word, node)) return false;
        return node->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        return isPrefix(prefix, node);
    }

private:
    TrieNode* root;
};
