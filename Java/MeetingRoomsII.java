// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
// (si < ei), find the minimum number of conference rooms required.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.

public class MeetingRoomsII {
    public int minMeetingRooms(Interval[] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, (Interval i1, Interval i2) -> i1.start - i2.start);
        int numRooms = 1;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(intervals[0].end);
        for (int i = 1; i < intervals.length; i++) {
            while (!pq.isEmpty() && pq.peek() <= intervals[i].start) {
                pq.poll();
            }
            pq.add(intervals[i].end);
            numRooms = Math.max(numRooms, pq.size());
        }
        return numRooms;
    }
}
