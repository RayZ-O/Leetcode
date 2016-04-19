// Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its
// missing ranges.

// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

public class MissingRanges {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> missingRanges = new ArrayList<>();
        int pre = lower - 1;
        for (int i = 0; i <= nums.length; i++) {
            int cur = i < nums.length ? nums[i] : upper + 1;
            if (cur - pre == 2) {
                missingRanges.add(Integer.toString(pre + 1));
            }
            if (cur - pre > 2) {
                missingRanges.add(Integer.toString(pre + 1)+"->"+Integer.toString(cur - 1));
            }
            pre = cur;
        }
        return missingRanges;
    }
}
