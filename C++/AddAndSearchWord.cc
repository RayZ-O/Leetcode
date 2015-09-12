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

class TrieNode {
public:
    bool wordEnd[26];
    TrieNode* children[26];
    TrieNode* oneOfChildren;
    TrieNode* sibling;
    TrieNode() : oneOfChildren(nullptr), sibling(this){
        for (int i = 0; i < 26; i++) {
            wordEnd[i] = false;
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool recursivSearch(string word, TrieNode* node) {
        for (int i = 0; i < word.size() - 1; i++) {
            if (word[i] == '.') { 
                // find a next level node
                if (!node->oneOfChildren) {
                    TrieNode* beg = node;
                    do {                    
                        node = node->sibling;
                    } while (!node->oneOfChildren && beg != node);

                }
                TrieNode* nlNode = node->oneOfChildren;
                // if next level node exist
                if (nlNode) {
                    TrieNode* runner = nlNode; 
                    do {
                        // try each node in this level to match the remaining string
                        if (recursivSearch(word.substr(i + 1), runner))
                            return true;
                        runner = runner->sibling;
                    } while (runner != nlNode);
                }    
                return false;
            } 
            if (!node->children[word[i] - 'a'])  
                return false;
            node = node->children[word[i] - 'a'];
        }
        // check the last character
        if (word.back() == '.') 
            return true;
        else 
            return node->wordEnd[word.back() - 'a'];
    }

public:
    WordDictionary() : root(new TrieNode()) { }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size() - 1; i++) {
            if (!node->children[word[i] - 'a']) {
                TrieNode* newNode = new TrieNode();
                node->children[word[i] - 'a'] = newNode;
                // if this is the first child
                if (!node->oneOfChildren) {
                    node->oneOfChildren = newNode;
                    TrieNode* runner = node->sibling;
                    // check if any other node on this level
                    while (runner != node) {
                        if (runner->oneOfChildren) {
                            newNode->sibling = runner->oneOfChildren->sibling;
                            runner->oneOfChildren->sibling = newNode;
                            break;
                        }
                        runner = runner->sibling;
                    }
                } else {
                    newNode->sibling = node->oneOfChildren->sibling;
                    node->oneOfChildren->sibling = newNode;
                }
            }
            node = node->children[word[i] - 'a'];
        }
        // set wordEnd field for last character
        node->wordEnd[word.back() - 'a'] = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return recursivSearch(word, root);
    }
};
