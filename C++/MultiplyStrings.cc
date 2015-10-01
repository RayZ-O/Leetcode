// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.

class Solution {
    int toNum(const char c) {
        return c - '0';
    }
public:
    string multiply(string num1, string num2) {
        size_t m = num1.size();
        size_t n = num2.size();
        string output(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int cur = carry + toNum(num1[i]) * toNum(num2[j]) + toNum(output[i + j + 1]);
                output[i + j + 1] = cur % 10;
                carry = cur / 10;
            }
            output[i] += carry;
        }
        size_t beg = output.find_first_not_of('0');
        if (beg == string::npos) return "0";
        return output.substr(beg);
    }
};
