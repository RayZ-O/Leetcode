// Write a function to find the longest common prefix string amongst an array of strings. 

class Solution {
public:
	// Vertical
    string longestCommonPrefix1(vector<string>& strs) {
        string result;
        if (strs.empty()) return "";
        if (strs[0].empty()) return "";
        int min = strs[0].size();
        for (auto &s : strs) {
        	if(s.size() == 0) return "";
        	if(s[0] != strs[0][0]) return "";
        	if(s.size() < min) min = s.size();
        }
        result += strs[0][0];
        for (int i = 1; i < min; ++i) {
        	 for (auto &s : strs) {
        	 	if (s[i] != strs[0][i]) return result;
        	 }
        	 result += strs[0][i];
        }
        return result;
    }

    // Horizontal 
    string longestCommonPrefix2(vector<string>& strs) {
        string result;
        if (strs.empty()) return result;
        result = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
        	int size = min(result.size(), strs[i].size());
        	int j = 0;
        	for (; j < size; ++j) {
        		if (result[j] != strs[i][j])  break;
        	}
        	result = result.substr(0, j);
        	if (result.empty()) break;
        }
        return result;
    }
};