// An abbreviation of a word follows the form <first letter><number><last letter>.
// Below are some examples of word abbreviations:

// a) it                      --> it    (no abbreviation)

//      1
// b) d|o|g                   --> d1g

//               1    1  1
//      1---5----0----5--8
// c) i|nternationalizatio|n  --> i18n

//               1
//      1---5----0
// d) l|ocalizatio|n          --> l10n

// Assume you have a dictionary and given a word, find whether its abbreviation is unique
// in the dictionary. A word's abbreviation is unique if no other word from the dictionary
// has the same abbreviation.

// Example:

// Given dictionary = [ "deer", "door", "cake", "card" ]

// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> abbv_word_;

    string toAbbv(const string& word) {
        string mid = word.size() > 2 ? to_string(word.size() - 2) : "";
        return word.front() + mid + word.back();
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto s : dictionary) {
            abbv_word_[toAbbv(s)].insert(s);
        }
    }

    bool isUnique(string word) {
        string abbv = toAbbv(word);
        if (abbv_word_.find(abbv) == abbv_word_.end()) {
            return true;
        }
        const unordered_set<string>& word_set = abbv_word_[abbv];
        return word_set.size() == 1 && word_set.find(word) != word_set.end();
    }
};

