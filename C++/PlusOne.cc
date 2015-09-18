// Given a non-negative number represented as an array of digits, plus one to the number.

// The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 ) {
            if (digits[i] != 9) break;
            i--;
        }
        if (i < 0) {
            vector<int> output{1};
            output.insert(output.end(), digits.size(), 0);
            return output;
        } else {
            vector<int> output(digits.begin(), digits.begin() + i + 1);
            output.insert(output.end(), digits.size() - i - 1, 0);
            output[i]++;
            return output;
        }
    }
};
