// Given an unsorted array, find the maximum difference between the successive elements in
// its sorted form.

// Try to solve it in linear time/space.

// Return 0 if the array contains less than 2 elements.

// You may assume all elements in the array are non-negative integers and fit in the 32-bit
// signed integer range.

class Solution {
    struct Bucket {
        int max;
        int min;
        bool touched;
        Bucket() : touched(false) {}
    };
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int max_elem = *max_element(nums.begin(), nums.end());
        int min_elem = *min_element(nums.begin(), nums.end());
        int gap = ceil((max_elem - min_elem)/ (n - 1.0));
        vector<Bucket> buckets(n - 1, Bucket());
        for (int i : nums) {
            if (i != max_elem) {
                int idx = (i - min_elem) / gap;
                if (!buckets[idx].touched) {
                    buckets[idx].max = buckets[idx].min = i;
                    buckets[idx].touched = true;
                } else {
                    buckets[idx].max = max(i, buckets[idx].max);
                    buckets[idx].min = min(i, buckets[idx].min);
                }
            }
        }
        int max_gap = 0;
        int prev = min_elem;
        for (auto& b : buckets) {
            if (b.touched) {
                max_gap = max(max_gap, b.min - prev);
                prev = b.max;
            }
        }
        max_gap = max(max_gap, max_elem - prev);
        return max_gap;
    }
};
