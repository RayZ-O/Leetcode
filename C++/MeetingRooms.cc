// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return false.

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(),
            [](Interval intv1, Interval intv2) {
                return intv1.start < intv2.start;
            });
        for (auto it = intervals.begin(); it != intervals.end() - 1; it++) {
            if (it->end > (it + 1)->start) {
                return false;
            }
        }
        return true;
    }
};
