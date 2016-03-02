// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples 
// of word abbreviations:

// a) it                      --> it    (no abbreviation)

//      1
// b) d|o|g                   --> d1g

//               1    1  1
//      1---5----0----5--8
// c) i|nternationalizatio|n  --> i18n

//               1
//      1---5----0
// d) l|ocalizatio|n          --> l10n
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. 
// A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

// Example: 
// Given dictionary = [ "deer", "door", "cake", "card" ]

// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true

public class ValidWordAbbr {
    Map<String, String> mp = new HashMap<>();

    public ValidWordAbbr(String[] dictionary) {
        for (String s : dictionary) {
            String ab = abbreviation(s);
            if (mp.containsKey(ab) && !mp.get(ab).equals(s)) {
                mp.put(ab, "");
            } else {
                mp.put(ab, s);
            }

        }
    }

    public boolean isUnique(String word) {
        String ab = abbreviation(word);
        return !mp.containsKey(ab) || mp.get(ab).equals(word);
    }

    String abbreviation(String s) {
        if (s.isEmpty()) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        sb.append(s.charAt(0));
        int count = 0;
        for (int i = 1; i < s.length() - 1; i++) {
            count++;
        }
        if (count != 0) {
            sb.append(count);
        }
        sb.append(s.charAt(s.length() - 1));
        return sb.toString();
    }
}
