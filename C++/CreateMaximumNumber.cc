// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number
// of length k <= m + n from digits of the two. The relative order of the digits from the same array must
// be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

// Example 1:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// return [9, 8, 6, 5, 3]

// Example 2:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// return [6, 7, 6, 0, 4]

// Example 3:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// return [9, 8, 9]

class Solution {
    vector<int> maxNumber(vector<int>& nums, int k) {
        vector<int> output;
        int n = nums.size();
        for (int i = 0; i < n ; i++) {
            while (!output.empty() && output.back() < nums[i] && output.size() + n - i > k) {
                output.pop_back();
            }
            if (output.size() < k) {
                output.push_back(nums[i]);
            }
        }
        return output;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> output;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 != nums1.end() || it2 != nums2.end()) {
            auto &t = lexicographical_compare(it1, nums1.end(), it2, nums2.end()) ? it2 : it1;
            output.push_back(*t);
            ++t;
        }
        return output;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> output(k, 0);
        int n1 = nums1.size() , n2 = nums2.size();
        for (int i = max(0, k - n2); i <= min(n1, k); i++) {
            vector<int> m = merge(maxNumber(nums1, i), maxNumber(nums2, k - i));
            if (lexicographical_compare(output.begin(), output.end(), m.begin(), m.end())) {
                output.swap(m);
            }
        }
        return output;
    }
};
