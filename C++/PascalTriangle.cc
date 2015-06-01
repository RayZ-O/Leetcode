// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	if (numRows < 1) {
        	return vector<vector<int>>{};
        }
        vector<vector<int>> result(numRows, {1});        
        for (int n = 1; n < numRows; ++n) {
        	for (int i = 0; i < n-1; ++i) {
        		result[n].push_back(result[n-1][i] + result[n-1][i+1]);
        	}
        	result[n].push_back(1);
        }
        return result;
    }
};
