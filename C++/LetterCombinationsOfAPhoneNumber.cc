// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters is just like on the telephone buttons.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
    void generateCombinations(string digits, string cur, vector<string>& output, unordered_map<char, string>& digitToLetter) {
        for (char c : digitToLetter[digits[0]]) {
            if (digits.size() == 1) {
                output.push_back(cur + c);
                continue;
            }
            generateCombinations(digits.substr(1), cur + c, output, digitToLetter);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if(digits.empty()) return output;
        unordered_map<char, string> digitToLetter{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                                                  {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        generateCombinations(digits, "", output, digitToLetter);
        return output;
    }
};
