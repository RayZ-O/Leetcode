// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest
// transformation sequence from beginWord to endWord, such that:

// 1.Only one letter can be changed at a time
// 2.Each intermediate word must exist in the word list
// For example,

// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        int length = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto w = q.front();
                if (w == endWord) {
                    return length;
                }
                for (char& c : w) {
                   char temp = c;
                   for (char alt = 'a'; alt <= 'z'; alt++) {
                       c = alt;
                       if (wordList.find(w) != wordList.end()) {
                           q.push(w);
                           wordList.erase(w);
                       }
                   }
                   c = temp;
               }
               q.pop();
            }
            length++;
        }
        return 0;
    }
};
