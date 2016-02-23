// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at
// upside down).

// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// For example, the numbers "69", "88", and "818" are all strobogrammatic.

public class StrobogrammaticNumber {
    public boolean isStrobogrammatic(String num) {
        Map<Character, Character> mp = new HashMap<>();
        mp.put('0','0');
        mp.put('1','1');
        mp.put('6','9');
        mp.put('8','8');
        mp.put('9','6');
        int i = 0, j = num.length() - 1;
        while (i < j) {
            if (mp.get(num.charAt(i)) == null || mp.get(num.charAt(i)) != num.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return i != j ? true : (num.charAt(i) == '0' || num.charAt(i) == '1' || num.charAt(i) == '8');
    }
}
