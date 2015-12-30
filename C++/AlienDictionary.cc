// There is a new alien language which uses the latin alphabet. However,
// the order among letters are unknown to you. You receive a list of words
// from the dictionary, where words are sorted lexicographically by the rules
// of this new language. Derive the order of letters in this language.

// For example,
// Given the following words in dictionary,

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".

// Note:
// You may assume all letters are in lowercase.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.

class Solution {
    using adj_list = unordered_set<char>;
    enum class Color {WHITE, GRAY, BLACK};

    bool dfs(unordered_map<char, adj_list> &graph, char node, unordered_map<char, Color> &color, string &output) {
        color[node] = Color::GRAY;
        for (char c : graph[node]) {
            if (color[c] == Color::WHITE && !dfs(graph, c, color, output)) {
                return false;
            }
            if (color[c] == Color::GRAY) {
                return false;
            }
        }
        output += node;
        color[node] = Color::BLACK;
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, adj_list> graph;
        unordered_map<char, Color> color;
        for (const auto& word: words) {
            for (auto c : word) {
                if(graph.find(c) == graph.end()) {
                    graph[c] = adj_list();
                    color[c] = Color::WHITE;
                }
            }
        }
        for (int i = 1; i < words.size(); i++) {
            int len = min(words[i - 1].size(), words[i].size());
            for (int j = 0; j < len; j++) {
                if (words[i - 1][j] != words[i][j]) {
                    graph[words[i][j]].insert(words[i - 1][j]);
                    break;
                }
            }
        }
        string output;
        for (auto g : graph) {
            if (color[g.first] == Color::WHITE && !dfs(graph, g.first, color, output)) {
                return "";
            }
        }
        return output;
    }
};

