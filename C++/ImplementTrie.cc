// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode;

struct charInfo {
    bool exist;
    TrieNode* next;
};

class TrieNode { 
public:
    unordered_map<char, charInfo> chars;
    // Initialize your data structure here.
    TrieNode() : chars() { }
};

class Trie {
    bool isPrefix(string word, TrieNode* &node) {
         for (int i = 0; i < word.size() - 1; i++) {
            if(node->chars.find(word[i]) == node->chars.end() || !node->chars[word[i]].next) {
                return false;
            }
            node = node->chars[word[i]].next;
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
        for (int i = 0; i < word.size() - 1; i++) {
            if(node->chars.find(word[i]) == node->chars.end()) {
                node->chars.emplace(word[i], charInfo{false, new TrieNode()});
            } else if (!node->chars[word[i]].next) {
                node->chars[word[i]].next = new TrieNode();
            }
            node = node->chars[word[i]].next;
        }
        if(node->chars.find(word.back()) == node->chars.end()) 
            node->chars.emplace(word.back(), charInfo{true, nullptr});
        else
            node->chars[word.back()].exist = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        if (!isPrefix(word, node) || node->chars.find(word.back()) == node->chars.end()) {
            return false;
        }
        return node->chars[word.back()].exist;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        if (!isPrefix(prefix, node) || node->chars.find(prefix.back()) == node->chars.end()) {
            return false;
        }
        return true;
    }

private:
    TrieNode* root;
};