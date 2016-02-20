// Given an array of integers, every element appears twice except for one. Find that single one.

public class SingleNumber {
    public int singleNumber(int[] nums) {
        int out = 0;
        for (int i : nums) {
            out ^= i;
        }
        return out;
    }
}
