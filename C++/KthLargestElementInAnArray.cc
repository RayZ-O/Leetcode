// Find the kth largest element in an unsorted array. Note that
// it is the kth largest element in the sorted order, not the
// kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) return -1;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto n : nums) {
            if (min_heap.size() < k) {
                min_heap.push(n);
                continue;
            }
            if (n > min_heap.top()) {
                min_heap.pop();
                min_heap.push(n);
            }
        }
        return min_heap.top();
    }
};

