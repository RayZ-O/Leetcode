// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
// return 964176192 (represented in binary as 00111001011110000010100101000000).

public class ReverseBits {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int r = 0;
        for (int i = 0; i < 31; i++) {
            r |= (n & 1);
            r <<= 1;
            n >>>= 1;
        }
        r |= (n & 1);
        return r;
    }
}
