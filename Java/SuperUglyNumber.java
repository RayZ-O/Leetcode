// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of 
// size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super 
// ugly numbers given primes = [2, 7, 13, 19] of size 4.

// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

public class SuperUglyNumber {
    class Run {
        int value;
        int base;
        int idx;
        Run(int value, int base, int idx) {
            this.value = value;
            this.base = base;
            this.idx = idx;
        }
    }
    
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] uglyNumbers = new int[n];
        uglyNumbers[0] = 1;
        PriorityQueue<Run> pq = new PriorityQueue<>(primes.length, (Run r1, Run r2) -> r1.value - r2.value);
        for (int p : primes) {
            pq.add(new Run(p, p, 1));
        }
        for (int i = 1; i < n; i++) {
            uglyNumbers[i] = pq.peek().value;
            while (uglyNumbers[i] == pq.peek().value) {
                Run r = pq.poll();
                pq.add(new Run(r.base * uglyNumbers[r.idx], r.base, r.idx+1));
            }
        }
        return uglyNumbers[n-1];
    }
}
