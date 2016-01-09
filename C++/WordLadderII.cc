// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest
// transformation sequence(s) from beginWord to endWord, such that:

// 1.Only one letter can be changed at a time
// 2.Each intermediate word must exist in the word list
// For example,

// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
    using graph = unordered_map<string, vector<string>>;
    const int kImax = numeric_limits<int>::max();

    bool bfs(string& beginWord, string& endWord, unordered_set<string>& wordList, graph& g) {
        unordered_map<string, int> dists;
        dists.emplace(beginWord, 1);
        for (auto& s : wordList) {
            dists.emplace(s, kImax);
        }
        queue<string> q;
        q.push(beginWord);
        int length = 1;
        bool can_reach = false;
        while (!q.empty() && !can_reach) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                const string cw = q.front();
                if (cw == endWord) {
                    can_reach = true;
                }
                string w = cw;
                for (char& c : w) {
                    char temp = c;
                    for (char alt = 'a'; alt <= 'z'; alt++) {
                        c = alt;
                        if (wordList.find(w) != wordList.end()) {
                            if (dists[w] < length) {
                                continue;
                            } else if (dists[w] > length) {
                                q.push(w);
                                dists[w] = length;
                            }
                            g[w].push_back(cw);
                        }
                    }
                    c = temp;
                }
                q.pop();
            }
            length++;
        }
        return can_reach;
    }

    void dfs(string& beginWord, string& curWord, graph& g, vector<string> cur, vector<vector<string>>& output) {
        cur.push_back(curWord);
        if (curWord == beginWord) {
            reverse(cur.begin(), cur.end());
            output.push_back(cur);
            return;
        }
        for (auto& w : g[curWord]) {
            dfs(beginWord, w, g, cur, output);
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        graph g;
        wordList.insert(endWord);
        bfs(beginWord, endWord, wordList, g);
        vector<vector<string>> output;
        vector<string> cur;
        dfs(beginWord, endWord, g, cur, output);
        return output;
    }
};
