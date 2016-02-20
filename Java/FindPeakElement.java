// A peak element is an element that is greater than its neighbors.

// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that num[-1] = num[n] = -∞.

// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index
// number 2.

public class FindPeakElement {
    public int findPeakElement(int[] nums) {
        int n = nums.length - 1;
        int l = 0, h = n;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (mid > 0 && nums[mid] < nums[mid-1]) {
                h = mid - 1;
            } else if (mid < n && nums[mid] < nums[mid+1]) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
