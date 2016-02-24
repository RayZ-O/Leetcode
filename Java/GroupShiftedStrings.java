// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd".
// We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the
// same shifting sequence.

// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Return:

// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
// Note: For the return value, each inner list's elements must follow the lexicographic order.

public class GroupShiftedStrings {
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> mp = new HashMap<>();
        for (String s : strings) {
            if (s.length() == 0) {
                mp.put("", new ArrayList<String>(){{add("");}});
            } else {
                char[] ca = s.toCharArray();
                int diff = 'z' - ca[0];
                for (int i = 0; i < ca.length; i++) {
                    ca[i] += diff;
                    if (ca[i] > 'z') {
                        ca[i] -= 26;
                    }
                }
                String n = new String(ca);
                System.out.println(s + " " + n);
                if (mp.get(n) == null) {
                    mp.put(n, new ArrayList<String>(){{add(s);}});
                } else {
                    mp.get(n).add(s);
                }
            }
        }
        List<List<String>> out = new ArrayList<>();
        for (List<String> l : mp.values()) {
            Collections.sort(l);
            out.add(l);
        }
        return out;
    }
}
