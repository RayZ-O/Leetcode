// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        int pos = 0;
        while (n) {
        	pos = (n - 1) % 26;
        	result.push_back(pos + 'A');
        	n = (n - pos - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};