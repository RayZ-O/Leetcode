// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.

public class IntegerToRoman {
    public String intToRoman(int num) {
        String[] roman = new String[]{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int[] decimal = new int[]{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int i = decimal.length - 1;
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            if (num >= decimal[i]) {
                sb.append(roman[i]);
                num -= decimal[i];
            } else {
                i--;
            }
        }
        return sb.toString();
    }
}
