// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence
// where each word is a valid dictionary word.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].

// A solution is ["cats and dog", "cat sand dog"].

class Solution {
    unordered_map<int, vector<string>> store;

    vector<string> collect(string& s, int beg, unordered_set<string>& wordDict) {
        if (store.find(beg) != store.end()) {
            return store[beg];
        }
        vector<string> output;
        string whole = s.substr(beg);
        if (wordDict.find(whole) != wordDict.end()) {
            output.push_back(whole);
        }
        for (int i = beg; i < s.size() - 1; i++) {
            string word = s.substr(beg, i - beg + 1);
            // cout << word << endl;
            if (wordDict.find(word) != wordDict.end()) {
                for (string st : collect(s, i + 1, wordDict)) {
                    output.push_back(word + ' ' + st);
                }
            }
        }
        store[beg] = output;
        return output;
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        return collect(s, 0, wordDict);
    }
};
