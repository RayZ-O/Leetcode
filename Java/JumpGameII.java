// Given an array of non-negative integers, you are initially positioned at the first index of 
// the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 
// steps to the last index.)

// Note:
// You can assume that you can always reach the last index.

public class JumpGameII {
    public int jump(int[] nums) {
        int step = 0;
        int beg = 0, end = 0;
        while (end < nums.length - 1) {
            int newEnd = end;
            for (int i = beg; i <= end; i++) {
                newEnd = Math.max(newEnd, i + nums[i]);
            }
            if (newEnd == end) return -1; // can't reach the end
            
            step++;
            beg = end + 1;
            end = newEnd;
        }
        return step;
    }
}
