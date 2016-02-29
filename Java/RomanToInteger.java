// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.

public class RomanToInteger {
    Map<Character, Integer> buildMap() {
        Map<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        return mp;
    }
    
    public int romanToInt(String s) {
        if (s.length() == 0) {
            return 0;
        }
        Map<Character, Integer> mp = buildMap();
        char[] ca = s.toCharArray();
        int num = mp.get(ca[ca.length-1]);
        for (int i = ca.length - 2; i >= 0; i--) {
            if (mp.get(ca[i]) < mp.get(ca[i+1])) {
                num -= mp.get(ca[i]);
            } else {
                num += mp.get(ca[i]);
            }
        }
        return num;
    }
}
