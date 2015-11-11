// Given a collection of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]

class Solution {
    void collectElem(int start, vector<int>& cur, vector<vector<int>>& output,
      vector<int>& candidates, int remain) {
        if (0 == remain) {
            output.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > remain)
                return;
            cur.push_back(candidates[i]);
            collectElem(i + 1, cur, output, candidates, remain - candidates[i]);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        collectElem(0, cur, output, candidates, target);
        return output;
    }
};
