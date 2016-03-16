// Implement atoi to convert a string to an integer.

// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below 
// and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are 
// responsible to gather all the input requirements up front.

public class StringToInteger {
    public int myAtoi(String str) {
        String num = str.trim();
        if (num.length() == 0) {
            return 0;
        }
        int res = 0;
        int sign = 1;
        int i = 0;
        // get sign
        if (num.charAt(i) == '-' || num.charAt(i) == '+')  {
            sign = num.charAt(i++) == '-' ? -1 : 1;
        }
        // get number
        while (i < num.length() && Character.isDigit(num.charAt(i))) {
            // handle overflow
            if (sign == 1) {
                if (res > (Integer.MAX_VALUE - Character.getNumericValue(num.charAt(i))) / 10) {
                    return Integer.MAX_VALUE;
                }
                res = res * 10 + Character.getNumericValue(num.charAt(i));
            } else {
                if (res < (Integer.MIN_VALUE + Character.getNumericValue(num.charAt(i))) / 10) {
                    return Integer.MIN_VALUE;
                }
                res = res * 10 - Character.getNumericValue(num.charAt(i));
            }
            i++;
        }
        return res;
    }
}
