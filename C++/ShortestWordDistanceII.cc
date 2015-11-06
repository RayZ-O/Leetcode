// This is a follow up of Shortest Word Distance. The only difference is now
// you are given the list of words and your method will be called repeatedly
// many times with different parameters. How would you optimize it?

// Design a class which receives a list of words in the constructor, and implements
// a method that takes two words word1 and word2 and return the shortest distance
// between these two words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class WordDistance {
    unordered_map<string, vector<int>> word_to_idx;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (word_to_idx.find(words[i]) != word_to_idx.end()) {
                word_to_idx[words[i]].push_back(i);
            } else {
                word_to_idx.emplace(words[i], vector<int>{i});
            }
        }
    }

    int shortest(string word1, string word2) {
        vector<int> v1 = word_to_idx[word1];
        vector<int> v2 = word_to_idx[word2];
        int min_diff =  abs(v1[0] - v2[0]);
        for (int i = 0, j = 0; i < v1.size() && j < v2.size();) {
            min_diff = min(min_diff, abs(v1[i] - v2[j]));
            v1[i] > v2[j] ? ++j : ++i;
        }
        return min_diff;
    }
};
