// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

// For example,

// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

class Solution {
public:
    string numberToWords(int num) {
        string output;
        if (num == 0) {
            output += "Zero";
        } else {
            unordered_map<int, string> convert_table{ {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, 
                                                  {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, 
                                                  {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
                                                  {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
                                                  {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
                                                  {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
                                                  {0, " "}, {300, "Thousand"}, {600, "Million"}, {900, "Billion"}
                                                };
            int cnt = 0;
            int remain = 0;
            stack<string> st;
            while (num) { 
                if (num % 1000 != 0 && cnt % 3 == 0) st.push(convert_table[cnt*100]);
                if (num % 10 != 0 && cnt % 3 == 2) st.push("Hundred"); 
                remain = (cnt % 3 == 0? num % 100 : num % 10);
                num /= (cnt % 3 == 0? 100 : 10);
                cnt += (cnt % 3 == 0? 2 : 1);
                if (remain <= 20) {
                    st.push(convert_table[remain]);
                } else if(remain < 100) {
                    st.push(convert_table[remain%10]);
                    st.push(convert_table[remain-remain%10]);
                }
            }        
                
            while (!st.empty()) {
                if (st.top() != " ") {
                    output += st.top() + " ";
                }                
                st.pop();
            }
            output.pop_back();
        }       
        return output; 
    }
};
