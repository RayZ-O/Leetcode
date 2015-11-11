// Find all possible combinations of k numbers that add up to a number n,
// given that only numbers from 1 to 9 can be used and each combination
// should be a unique set of numbers.

// Ensure that numbers within the set are sorted in ascending order.

// Example 1:
// Input: k = 3, n = 7
// Output:
// [[1,2,4]]

// Example 2:
// Input: k = 3, n = 9
// Output:
// [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
    void collectElem(int start, vector<int>& cur, vector<vector<int>>& output,
      int k, int remain) {
        if (0 == remain && cur.size() == k) {
            output.push_back(cur);
            return;
        }
        if (cur.size() >= k)
            return;
        for (int i = start; i < 10; ++i) {
            if (remain - i < 0)
                return;
            cur.push_back(i);
            collectElem(i + 1, cur, output, k, remain - i);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> cur;
        collectElem(1, cur, output, k, n);
        return output;
    }
};

