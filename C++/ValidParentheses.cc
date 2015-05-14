// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string s) {
        vector<char> brackets;
        unordered_map<char, char> match_table { {')', '('}, {']', '['}, {'}', '{'} };
        for (auto ch : s) {
        	switch(ch) {
        		case '(': case '[': case '{':
        			brackets.push_back(ch);
        			break;
        		case ')': case ']': case '}':
					if (!brackets.empty() && brackets.back() == match_table[ch]) {
						brackets.pop_back();
					} else {
						return false;
					}
					break;
				default:
					return false;
        	}
        }
        if (brackets.empty())						
        	return true;
        else
        	return false;
    }
};