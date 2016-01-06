// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.

class Solution {
    const vector<int> factorials{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    void permute(vector<int>& nums, int n, int k, string& res) {
        if (nums.empty()) {
            return;
        }
        int seg_size = factorials[n] / n;
        int idx = (k - 1) / seg_size;
        res += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);
        permute(nums, n - 1, (k - 1) % seg_size + 1, res);
    }
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string res;
        permute(nums, n, k, res);
        return res;
    }
};
