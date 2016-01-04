// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// The algorithm should run in linear time and in O(1) space.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> elems;
        for (int n : nums) {
            elems[n]++;
        }
        vector<int> output;
        for (auto p : elems) {
            if (p.second > nums.size() / 3) {
                output.push_back(p.first);
            }
        }
        return output;
    }
};
