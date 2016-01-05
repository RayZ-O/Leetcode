// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
// (si < ei), find the minimum number of conference rooms required.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(),
            [](const Interval& i1, const Interval& i2){return i1.start < i2.start;});

        priority_queue<int,vector<int>, greater<int>> pq;
        pq.push(intervals[0].end);
        int count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < pq.top() && count == pq.size()) {
                count++;
            }
            while (!pq.empty() && intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return count;
    }
};

