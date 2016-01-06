// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime
// list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the
// sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

class Solution {
    using Tuple = tuple<int, int, int>;
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n < 1) {
            return 0;
        }
        vector<int> un(n, 1);
        auto comp = [](const Tuple& t1, const Tuple& t2) { return get<0>(t1) > get<0>(t2); };
        priority_queue<Tuple, vector<Tuple>, decltype(comp)> pq(comp);
        for (int i = 0; i < primes.size(); i++) {
            pq.emplace(primes[i], 0, primes[i]);
        }
        for (int i = 1; i < n; i++) {
            un[i] = get<0>(pq.top());
            while (un[i] == get<0>(pq.top())) {
                int idx = get<1>(pq.top()) + 1;
                int factor = get<2>(pq.top());
                pq.pop();
                pq.emplace(un[idx] * factor, idx, factor);
            }
        }
        return un[n - 1];
    }
};
