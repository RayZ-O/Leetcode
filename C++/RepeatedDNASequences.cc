// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example:
// "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within
// the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than
// once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> output;
        if (s.size() < 10) {
            return output;
        }
        int mask = (1 << 30) - 1;
        unordered_map<int, int> seqs;
        for (int i = 0; i < s.size(); i++) {
            int b = (b << 3) & mask | s[i] & 7;
            if (seqs[b]++ == 1) {
                output.push_back(s.substr(i - 9, 10));
            }
        }
        return output;
    }
};
