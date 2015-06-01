// Given an index k, return the k-th row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1]. 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int>{};
        }
        vector<int> prev(rowIndex + 1, 1); 
        vector<int> result(rowIndex + 1, 1);        
        for(int n = 1; n <= rowIndex; ++n) {
            result.swap(prev);
            for(int i = 1; i <= n/2; ++i) {
                result[n-i] = result[i] = prev[i-1] + prev[i];
            }            
        }
        return result;
    }
};