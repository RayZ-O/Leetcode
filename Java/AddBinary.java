// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

public class AddBinary {
    public String addBinary(String a, String b) {
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        StringBuilder sb = new StringBuilder();
        while (i >= 0 || j >= 0 || carry == 1) {
            int l = 0, r = 0;
            if (i >= 0) {
                l = a.charAt(i--) - '0';
            }
            if (j >= 0) {
                r = b.charAt(j--) - '0';
            }
            int res = l + r + carry;
            sb.append(res % 2);
            carry = res / 2;
        }
        return sb.reverse().toString();
    }
}
