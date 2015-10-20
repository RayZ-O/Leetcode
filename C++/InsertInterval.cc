// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) return vector<Interval>{newInterval};

        auto low_it = lower_bound(intervals.begin(), intervals.end(), newInterval,
                                [](const Interval &intv1, const Interval &intv2) {
                                    return intv1.end < intv2.start;
                                });
        auto up_it = lower_bound(intervals.begin(), intervals.end(), newInterval,
                                [](const Interval &intv1, const Interval &intv2) {
                                    return intv1.start <= intv2.end;
                                });
        if (low_it == up_it)
            intervals.insert(up_it, newInterval);
        else {
            low_it->start = min(low_it->start, newInterval.start);
            low_it->end = max((up_it - 1)->end, newInterval.end);
            intervals.erase(low_it + 1, up_it);
        }
        return intervals;
    }
};
