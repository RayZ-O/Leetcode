// Given a sorted integer array without duplicates, return the summary of its ranges.

// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

public class SummaryRanges {
    public List<String> summaryRanges(int[] nums) {
        List<String> out = new ArrayList<>();
        if (nums.length == 0) {
            return out;
        }
        int beg = nums[0];
        for (int i = 1; i <= nums.length; i++) {
            if (i == nums.length || nums[i] != nums[i-1] + 1) {
                if (nums[i-1] == beg) {
                    out.add(Integer.toString(beg));
                } else {
                    out.add(Integer.toString(beg)+"->"+Integer.toString(nums[i-1]));
                }
                if (i < nums.length) {
                    beg = nums[i];
                }
            }
        }
        return out;
    }
}
