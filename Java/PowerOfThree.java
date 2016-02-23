// Given an integer, write a function to determine if it is a power of three.

// Follow up:
// Could you do it without using any loop / recursion?

public class PowerOfThree {
    final int maxPow = (int) Math.pow(3, 19);
    public boolean isPowerOfThree(int n) {
        return n > 0 &&  maxPow % n == 0;
    }
}
