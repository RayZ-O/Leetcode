// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto n : nums) {
            set.insert(n);
        }
        int max_length = 0;
        for (auto n : nums) {
            int count = 1;
            for (int i = n - 1; set.find(i) != set.end(); i--) {
                count++;
                set.erase(i);
            }
            for (int i = n + 1; set.find(i) != set.end(); i++) {
                count++;
                set.erase(i);
            }
            max_length = max(count, max_length);
        }
        return max_length;
    }
};
