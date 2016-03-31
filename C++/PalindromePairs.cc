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

class Solution {
    struct TrieNode {
        map<char, TrieNode*> children;
        int index;
        vector<int> indices;
        TrieNode() : index(-1) {}
        ~TrieNode() { 
            for (auto p : children) {
                delete p.second;
            }
        }
    };
    
    class Trie {
    private:
        TrieNode* root;
    public:
        Trie() : root(new TrieNode()) {}
        
        ~Trie() { delete root; }
        
        void reverse_insert(string &word, int wi) {
            TrieNode* node = root;
            for (int i = word.size() - 1; i >= 0; i--) {
                if (node->children.count(word[i]) == 0) {
                    node->children.emplace(word[i], new TrieNode());
                }
                node->indices.push_back(wi); 
                node = node->children[word[i]];
            }
            node->index = wi;
        }
        
        void find_pair(string &word, int idx, vector<string>& words, vector<vector<int>> &pairs) {
            if (root->index >= 0 && idx != root->index) {
                if (is_palindrome(word)) {
                    pairs.emplace_back(vector<int>{idx, root->index});
                }
            }
            TrieNode* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (node->children.count(word[i]) == 0) return;
                node = node->children[word[i]];
                if (node->index >= 0 && node->index != idx && is_palindrome(word+words[node->index])) {
                    pairs.emplace_back(vector<int>{idx, node->index});
                }
            }
            for (int wi : node->indices) {
                if (is_palindrome(word+words[wi])) {
                    pairs.emplace_back(vector<int>{idx, wi});
                }
            }
        }
        
        bool is_palindrome(string s) {
            for (int i = 0, j = s.size()-1; i < j; i++, j--) {
                if (s[i] != s[j]) return false;
            }
            return true;
        }
    };

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            trie.reverse_insert(words[i], i);
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            trie.find_pair(words[i], i, words, res);
        }
        return res; 
    }
};
