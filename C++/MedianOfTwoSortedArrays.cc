// There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two
// sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int k = (m + n + 1) / 2;
        int low = 0, high = m;
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = k - i;
            if (i < m && j >0 && nums1[i] < nums2[j-1]) {
                low = i + 1;
            } else if (j < n && i > 0 && nums1[i-1] > nums2[j]) {
                high = i - 1;
            } else {
                int n1 = i != 0 ? nums1[i-1] : nums2[j-1];
                int n2 = j != 0 ? nums2[j-1] : nums1[i-1];
                int left = max(n1, n2);
                if ((m + n) % 2) {
                    return left;
                }
                n1 = i != m ? nums1[i] : nums2[j];
                n2 = j != n ? nums2[j] : nums1[i];
                int right = min(n1, n2);
                return (static_cast<double>(left) + right) / 2;
            }
        }
        return -1.0;
    }
};
