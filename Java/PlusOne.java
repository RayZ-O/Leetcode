// Given a non-negative number represented as an array of digits, plus one to the number.

// The digits are stored such that the most significant digit is at the head of the list.

public class PlusOne {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0) {
                break;
            }
        }
        if (carry == 0) {
            return digits;
        } else {
            int[] des=new int[digits.length+1];
            des[0] = 1;
            System.arraycopy(digits, 0, des, 1, digits.length);
            return des;
        }
    }
}
