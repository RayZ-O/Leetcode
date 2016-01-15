// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.
// Example:
// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

class NumArray {
    vector<int> binary_indexed_tree;
    vector<int>& nums_;

    int getSum(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += binary_indexed_tree[i];
            i -= i & -i;
        }
        return sum;
    }

    void updateTree(int i, int inc) {
        i++;
        while (i < binary_indexed_tree.size()) {
            binary_indexed_tree[i] += inc;
            i += i & -i;
        }
    }
public:
    NumArray(vector<int> &nums) : nums_(nums) {
        binary_indexed_tree.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            updateTree(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int inc = val - nums_[i];
        nums_[i] = val;
        updateTree(i, inc);
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i - 1);
    }
};
