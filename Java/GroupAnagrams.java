// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:

// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
// For the return value, each inner list's elements must follow the lexicographic order.
// All inputs will be in lower-case.

public class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String n = new String(ca);
            mp.putIfAbsent(n, new ArrayList<>());
            mp.get(n).add(s);
        }
        List<List<String>> out = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry : mp.entrySet()) {
            out.add(entry.getValue());
            Collections.sort(out.get(out.size()-1));
        }
        return out;
    }
}
