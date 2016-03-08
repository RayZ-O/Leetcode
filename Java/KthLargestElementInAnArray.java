// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the 
// sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note: 
// You may assume k is always valid, 1 <= k <= array's length.

public class KthLargestElementInAnArray {
    public int findKthLargest(int[] nums, int k) {
        return select(nums, 0, nums.length - 1, nums.length - k);
    }

    int select(int[] nums, int l, int r, int k) {
        int p = partition(nums, l, r);
        if (p == k) {
            return nums[p];
        } else if (p < k) {
            return select(nums, p+1, r, k);
        } else {
            return select(nums, l, p-1, k);
        }
    }

    int partition(int[] nums, int l, int r) {
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] < nums[r]) {
                swap(nums, i, j);
                i++;
            }
        }
        swap(nums, i, r);
        return i;
    }

    void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
