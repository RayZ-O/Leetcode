// Given an array of words and a length L, format the text such that each line has exactly L
// characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in
// each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of
// spaces on a line do not divide evenly between words, the empty slots on the left will be
// assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between
// words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

class Solution {
    vector<int> assignSpace(int num_space, int num_split) {
        vector<int> spaces;
        while (num_split > 1) {
            int sp = num_space / num_split;
            spaces.push_back(sp);
            num_space -= sp;
            num_split--;
        }
        spaces.push_back(num_space);
        return spaces;
    }

    string join(vector<string>& words, vector<int>& spaces) {
        string line;
        auto rit = spaces.rbegin();
        for (auto& w : words) {
            line += w;
            if (rit != spaces.rend()) {
                line += string(*rit, ' ');
                ++rit;
            }
        }
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;

        vector<string> cur_words;
        int cur_len = 0;

        for (auto& w : words) {
            if (cur_len + w.size() + cur_words.size() <= maxWidth) {
                cur_len += w.size();
                cur_words.push_back(w);
            } else {
                int num_space = maxWidth - cur_len;
                auto spaces = assignSpace(num_space, cur_words.size() - 1);
                output.push_back(join(cur_words, spaces));
                cur_len = w.size();
                cur_words.assign({w});
            }
        }
        auto spaces = assignSpace(cur_words.size() - 1, cur_words.size() - 1);
        string last_line = join(cur_words, spaces);
        output.push_back(last_line + string(maxWidth - last_line.size(), ' '));
        return output;
    }
};
