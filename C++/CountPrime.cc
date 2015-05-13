// Count the number of prime numbers less than a non-negative number, n

// Sieve of Eratosthenes
//  for i = 2, 3, 4, ..., not exceeding √n:
//   if A[i] is true:
//     for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n:
//       A[j] := false
 
// Output: all i such that A[i] is true

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        } 
        vector<int> flags(n, 1);
        int s = sqrt(n);
        int count = n - 2;
        for (int i = 2; i <= s; ++i) {
            if (flags[i]) {
                for (int j = i*i; j <n; j += i) {
                    if (flags[j]) {
                        flags[j] = 0;
                        --count;
                    }
                }
            }
        }
        return count;
    }
};
