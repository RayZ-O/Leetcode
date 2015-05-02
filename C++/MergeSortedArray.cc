// Given two sorted integer arrays A and B, merge B into A as one sorted array.

// Note:
// You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
// The number of elements initialized in A and B are m and n respectively.

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m && !n){
            // nothing to do
        } else if (!m && n) {
            for (int i = 0; i < n; ++i) {
                A[i] = B[i];
            }
        } else {
            int curA = m - 1;
            int curB = n - 1;
            while(curA >= 0 && curB >= 0) {
                if(A[curA] < B[curB]) {
                    A[curA + curB + 1] = B[curB];
                    --curB;
                } else if (A[curA] >= B[curB]){
                    A[curA + curB + 1] = A[curA];
                    --curA;
                }
            }
            // if A run out of numbers earlier, than we're done
            // otherwise move the remaining numbers in B to A
            while (curB >= 0) {
                 A[curB] = B[curB];
                 --curB;
            }
        }
    }
};