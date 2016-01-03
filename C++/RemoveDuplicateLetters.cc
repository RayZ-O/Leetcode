// Given a string which contains only lowercase letters, remove duplicate letters so that
// every letter appear once and only once. You must make sure your result is the smallest
// in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> char_map;
        unordered_map<char, bool> in_stack;
        for (char c : s) {
            char_map[c]++;
            in_stack[c] = false;
        }
        stack<char> st;
        for (char c : s) {
            if (!in_stack[c]) {
                while (!st.empty() && c < st.top() && char_map[st.top()] > 0) {
                    in_stack[st.top()] = false;
                    st.pop();
                }
                st.push(c);
                in_stack[c] = true;
            }
            char_map[c]--;
        }
        string output;
        while (!st.empty()) {
            output += st.top();
            st.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
