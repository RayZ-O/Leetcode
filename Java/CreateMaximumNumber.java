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

public class CreateMaximumNumber {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] max = new int[k];
        for (int i = Math.max(0, k - nums2.length); i <= Math.min(k, nums1.length); i++) {
            int[] num = merge(maxKElements(nums1, i), maxKElements(nums2, k-i));
            if (lexicographicalCompare(num, 0, max, 0)) {
                max = num;
            }
        }
        return max;
    }

    int[] maxKElements(int[] nums, int k) {
        int[] maxK = new int[k];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            while (j > 0 && nums[i] > maxK[j-1] && j + nums.length - i > k) {
                j--;
            }
            if (j < k) {
                maxK[j++] = nums[i];
            }
        }
        return maxK;
    }

    boolean lexicographicalCompare(int[] nums1, int i, int[] nums2, int j) {
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] > nums2[j]) {
                return true;
            } else if (nums1[i] < nums2[j]) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        return i != nums1.length;
    }

    int[] merge(int[] nums1, int[] nums2) {
        int[] out = new int[nums1.length+nums2.length];
        int i = 0, j = 0, k = 0;
        while (k < out.length) {
            if (lexicographicalCompare(nums1, i, nums2, j)) {
                out[k++] = nums1[i++];
            } else {
                out[k++] = nums2[j++];
            }
        }
        return out;
    }
}
