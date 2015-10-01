// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.

class Solution {
    string multiplyChar(string num, char c, int n, vector<string>& res) {
        string re;
        int ci = c - '0';
        if (res[ci] != "") re = res[ci];
        else {
            int carry = 0;
            for (int i = num.size() - 1; i >= 0; i--) {
                int cur = carry + ci * (num[i] - '0');
                re = (char)(cur % 10 + '0') + re;
                carry = cur / 10;
            }
            if (carry) re = (char)(carry + '0') + re;
            res[ci] = re;
        }
        for (; n; n--) re += '0';
        return re;
    }
    string addStrings(string num1, string num2) {
        string re;
        for (int i = num1.size() - 1, j = num2.size() - 1, carry = 0; i >= 0 || j >=0 || carry; i--, j--) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int cur = carry + n1 + n2;
            re = (char)(cur % 10 + '0') + re;
            carry = cur / 10;
        }
        return re;
    }
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") return "0";
        vector<string> res(10, "");
        res[0] = "0";
        string output;
        int size = num2.size() - 1;
        for (int i = 0; i <= size; i++) {
            output = addStrings(output, multiplyChar(num1, num2[i], size - i, res));
        }
        return output;
    }
};
