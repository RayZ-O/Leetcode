// Given a string s, return all the palindromic permutations (without duplicates) of it.
// Return an empty list if no palindromic permutation could be form.

// For example:

// Given s = "aabb", return ["abba", "baab"].

// Given s = "abc", return [].

class Solution {
    bool nextPermutation(string& seed) {
        if (seed.size() < 2) {
            return false;
        }

        int i = seed.size() - 2;
        while (i >= 0 && seed[i] >= seed[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }

        int j = seed.size() - 1;
        while (j > i && seed[i] >= seed[j]) {
            j--;
        }

        swap(seed[i], seed[j]);
        reverse(seed.begin() + i + 1, seed.end());
        return true;

    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> dict;
        string seed = "";
        for (char c : s) {
            if (dict.count(c)) {
                seed += c;
                dict.erase(c);
            } else {
                dict[c]++;
            }
        }
        vector<string> output;
        if (dict.size() > 1) {
            return output;
        }
        string mid = dict.empty() ? "" : string(1, dict.begin()->first);
        sort(seed.begin(), seed.end());
        do {
            string t = seed;
            reverse(t.begin(), t.end());
            output.push_back(seed + mid + t);
        } while (nextPermutation(seed));
        return output;
    }
};
