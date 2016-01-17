// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of s1 = "great":

//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".

// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".

// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if (len == 0) {
            return true;
        }
        if (len != s2.size()) {
            return false;
        }
        vector<vector<vector<bool>>> v(len, vector<vector<bool>>(len, vector<bool>(len, false)));
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) {
                v[0][j][k] = s1[j] == s2[k];
            }
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < len - i; j++) {
                for (int k = 0; k < len - i; k++) {
                    for (int l = 0; l < i; l++) {
                        if (v[l][j][k] && v[i-l-1][j+l+1][k+l+1] || v[l][j][k+i-l] && v[i-l-1][j+l+1][k]) {
                            v[i][j][k] = true;
                        }
                    }
                }
            }
        }
        return v[len-1][0][0];
    }
};
