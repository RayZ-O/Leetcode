// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

public class MergeIntervals {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<>();
        Collections.sort(intervals, (Interval i1, Interval i2) -> i1.start - i2.start);
        Interval pre = null;
        for (Interval i : intervals) {
            if (res.isEmpty() || i.start > pre.end) {
                res.add(i);
                pre = i;
            } else {
                pre.end = Math.max(pre.end, i.end);
            }
        }
        return res;
    }
}
