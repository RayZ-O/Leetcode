// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers. Except for the first two numbers,
// each subsequent number in the sequence must be the sum of the preceding two.

// For example:
// "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
// 1 + 99 = 100, 99 + 100 = 199
// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

class Solution {
    string add(string n1, string n2) {
        int carry = 0;
        int i = n1.size() - 1, j = n2.size() - 1;
        string res;
        while (carry || i >= 0 || j >= 0) {
            int left = i >= 0 ? n1[i--] - '0' : 0;
            int right = j >= 0 ? n2[j--] - '0' : 0;
            int r = carry + left + right;
            carry = r / 10;
            res += (r % 10) + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool startsWith(string s, string t) {
        if (s.size() < t.size()) {
            return false;
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
    bool isValid(string n1, string n2, string remain) {
        if (n1.size() > 1 && startsWith(n1, "0") || n2.size() > 1 && startsWith(n2, "0")) {
            return false;
        }
        string sum = add(n1, n2);
        if (sum == remain) {
            return true;
        }
        if (!startsWith(remain, sum)) {
            return false;
        }
        return isValid(n2, sum, remain.substr(sum.size()));
    }
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= n / 2; j++) {
                if (isValid(num.substr(0, i), num.substr(i, j), num.substr(i+j))) {
                    return true;
                }
            }
        }
        return false;
    }
};
