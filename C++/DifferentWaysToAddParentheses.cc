// Given a string of numbers and operators, return all possible results from computing all the
// different possible ways to group numbers and operators. The valid operators are +, - and *.

// Example 1

// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2

// Output: [0, 2]

// Example 2

// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10

// Output: [-34, -14, -10, -10, 10]

class Solution {
    int eval(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
    }
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            if (!isdigit(input[i])) {
                for (int left : diffWaysToCompute(input.substr(0, i))) {
                    for (int right : diffWaysToCompute(input.substr(i + 1))) {
                        res.push_back(eval(left, right, input[i]));
                    }
                }
            }
        }
        return res.empty() ? vector<int>{stoi(input)} : res;
    }
};
