// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)

// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true

// Note:
// You may assume that all words are consist of lowercase letters a-z. 

class WordDictionary {
private:
    class TrieNode {
    public:
        bool isEnd;
        unordered_map<char, TrieNode*> chars;
        TrieNode() : isEnd(false) {  }
    };
    TrieNode* root; 

    bool recurseSearch(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                return any_of(node->chars.begin(), node->chars.end(),
                       [&](auto cs) {  // C++14 only, must specify type of cs in C++11
                           return this->recurseSearch(word.substr(i + 1), cs.second);
                       });
            }
            if(node->chars.find(word[i]) == node->chars.end()) {
                return false;
            }
            node = node->chars[word[i]];
        }
        return node->isEnd;
    }

public:
    WordDictionary() : root(new TrieNode()) { }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if(node->chars.find(word[i]) == node->chars.end()) {
                node->chars.emplace(word[i], new TrieNode());
            } 
            node = node->chars[word[i]];
        }
        node->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return recurseSearch(word, root);
    }
};
