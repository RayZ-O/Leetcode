// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note that 1 is typically treated as an ugly number.

public class UglyNumberII {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        pq.add(1L);
        for (int i = 1; i < n; i++) {
            long uglyNumber = pq.poll();
            while (!pq.isEmpty() && uglyNumber == pq.peek()) {
                pq.poll();
            }
            pq.add(uglyNumber * 2);
            pq.add(uglyNumber * 3);
            pq.add(uglyNumber * 5);
        }
        return pq.poll().intValue();
    }
}
