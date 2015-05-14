// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	if (nums.empty()) {
    		return "0";
    	}
        vector<string> nums_str;
        nums_str.reserve(nums.size());
        for(auto &n : nums) {
        	nums_str.push_back(to_string(n));
        }
        sort(nums_str.begin(), nums_str.end(), [](const string &s1, const string &s2) {	return (s1 + s2) > (s2 + s1); });
        string result;
        if (nums_str[0] == "0") {
        	result = "0";
        } else {
        	for(auto &s : nums_str) {
	        	result += s;
	        }
        }       
        return result;
    }
};