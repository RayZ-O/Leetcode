// Given a set of candidate numbers (C) and a target number (T), find all unique
// combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3]

class Solution {
    void collectElem(vector<int>& cur, vector<vector<int>>& output, vector<int>& candidates, int remain) {
        if (0 == remain) {
            output.push_back(cur);
            return;
        }
        for (int e : candidates) {
            if (remain - e < 0)
                continue;
            if (!cur.empty() && e < cur.back())
                continue;
            cur.push_back(e);
            collectElem(cur, output, candidates, remain - e);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        collectElem(cur, output, candidates, target);
        return output;
    }
};
