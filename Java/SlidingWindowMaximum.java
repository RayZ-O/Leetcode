// Given an array nums, there is a sliding window of size k which is moving from the very left of the 
// array to the very right. You can only see the k numbers in the window. Each time the sliding window 
// moves right by one position.

// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Therefore, return the max sliding window as [3,3,5,5,6,7].

public class SlidingWindowMaximum {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (k < 1) {
            return nums;
        }
        Deque<Integer> dq = new ArrayDeque<>();
        int[] out = new int[nums.length-k+1];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            while (!dq.isEmpty() && nums[i] >= nums[dq.getLast()]) {
                dq.removeLast();
            }
            dq.addLast(i);
            if (i - dq.getFirst() == k) {
                dq.removeFirst();
            }
            if (i >= k - 1) {
                out[j++] = nums[dq.getFirst()];
            }
        }
        return out;
    }
}
