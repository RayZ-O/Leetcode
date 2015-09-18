// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = '1'
// Return "100"

class Solution {
public:
    string addBinary(string a, string b) {
        string output;
        int carry = 0;
        auto ait = a.rbegin();
        auto bit = b.rbegin();
        while(ait != a.rend() || bit != b.rend() || carry) {
            int ai = ait == a.rend() ? 0 : *ait++ - '0';
            int bi = bit == b.rend() ? 0 : *bit++ - '0';
            int res = ai + bi + carry;
            output.push_back('0' + res % 2);
            carry = res / 2;
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
