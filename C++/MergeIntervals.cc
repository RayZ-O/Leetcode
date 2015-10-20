// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return vector<Interval>();
        sort(intervals.begin(), intervals.end(),
            [](const Interval &int1, const Interval &int2) {
                return int1.start < int2.start;
            });
        vector<Interval> output{ intervals[0] };
        for (int i = 1; i < intervals.size(); i++) {
            Interval &last = output.back();
            if (intervals[i].start <= last.end) {
                output.pop_back();
                output.emplace_back(last.start, max(intervals[i].end, last.end));
            } else {
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};
