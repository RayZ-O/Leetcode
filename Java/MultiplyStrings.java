// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.

public class MultiplyStrings {
     public String multiply(String num1, String num2) {
        int[] res = new int[num1.length()+num2.length()];
        for (int i = num1.length()-1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.length()-1; j >= 0 ; j--) {
                int n = (num2.charAt(j)-'0') * (num1.charAt(i)-'0') + carry + res[i+j+1];
                res[i+j+1] = n % 10;
                carry = n / 10;
            }
            res[i] = carry;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < res.length; i++) {
            if (sb.length() != 0 || res[i] != 0) {
                sb.append(res[i]);
            }
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
