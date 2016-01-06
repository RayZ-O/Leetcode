// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells
// are those horizontally or vertically neighboring. The same letter cell may not be used more than
// once in a word.

// For example,
// Given words = ["oath","pea","eat","rain"] and board =

// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode;

using node_ptr = shared_ptr<TrieNode>;
using child_map = unordered_map<char, node_ptr>;

class TrieNode {
public:
    child_map children;
    node_ptr parent;
    bool is_end;
    TrieNode() : children(), is_end(false) {}
};

class Trie {
    node_ptr root;
public:
    Trie(vector<string>& words) : root(node_ptr(new TrieNode())) {
        for (auto w : words) {
            insert(w);
        }
    }

    bool empty() {
        return root->children.empty();
    }

    void insert(string word) {
        node_ptr node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = node_ptr(new TrieNode());
                node->children[c]->parent = node;
            }
            node = node->children[c];
        }
        node->is_end = true;
    }

    // precondition: word in trie
    void erase(string word) {
        node_ptr node = root;
        for (char c : word) {
            node = node->children[c];
        }
        node->is_end = false;
        for (int i = word.size() - 1; i >= 0; i--) {
            if (!node->children.empty() || node->is_end) {
                break;
            }
            node->parent->children.erase(word[i]);
            node = node->parent;
        }
    }

    int search(string word) {
        node_ptr node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return 0;
            }
            node = node->children[c];
        }
        return node->is_end ? 2 : 1;
    }
};

class Solution {
    int m;
    int n;
    const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void findWords(vector<vector<char>>& board, int i, int j, string word, Trie& trie, vector<string>& output) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        word += board[i][j];
        int res = trie.search(word);
        if (!res) {
            return;
        }
        if (res == 2) {
            trie.erase(word);
            output.push_back(word);
        }

        board[i][j] = '*';
        for (auto d : dirs) {
            findWords(board, i + d.first, j + d.second, word, trie, output);
        }
        board[i][j] = word.back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board.empty() ? 0 : board[0].size();
        Trie trie(words);
        vector<string> output;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                findWords(board, i, j, "", trie, output);
            }
        }
        return output;
    }
};
