// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

class Solution {
    bool isPalindrome(string& t) {
        int n = t.size() - 1;
        for (int i = 0; i < t.size() / 2; i++) {
            if (t[n - i] != t[i]) {
                return false;
            }
        }
        return true;
    }

    void collect(vector<vector<string>>& output, vector<string>& cur, string& s, int beg) {
        if (beg == s.size() && !cur.empty()) {
            output.push_back(cur);
        }
        for (int i = beg; i < s.size(); i++) {
            string t = s.substr(beg, i - beg + 1);
            if (isPalindrome(t)) {
                cur.push_back(t);
                collect(output, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> cur;
        collect(output, cur, s, 0);
        return output;
    }
};
