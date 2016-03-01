// Count the number of prime numbers less than a non-negative number, n.

public class CountPrimes {
    public int countPrimes(int n) {
        boolean[] marks = new boolean[n];
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!marks[i]) {
                count++;
                if (n / i < i) continue;
                for (int j = i * i; j < n; j += i) {
                    marks[j] = true;
                }
            }
        }
        return count;
    }
}
