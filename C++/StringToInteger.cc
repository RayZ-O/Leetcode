class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
    	int i = 0;
    	// skip whitespace
    	while(isspace(str[i]) && i < size) {
    		++i;
    	}
    	// deal with sign
    	int sign = 1;
    	if (str[i] == '-') {
    		sign = -1;
    		++i;
    	} else if (str[i] == '+') {
    		++i;
    	}
    	int result = 0;
    	// deal with number
    	while(isdigit(str[i]) && i < size) {
    		int digit = str[i] - '0';
    		if ((INT_MAX - digit) / 10 < result) {
    			return sign == 1 ? INT_MAX : INT_MIN;
    		}
    		result = result * 10 + digit;
    		++i;
    	} 
    	return sign * result;
    }
};