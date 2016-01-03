// Given an array of numbers, verify whether it is the correct preorder traversal
// sequence of a binary search tree.

// You may assume each number in the sequence is unique.

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int prev = numeric_limits<int>::min();
        for (int i : preorder) {
            if (i < prev) {
                return false;
            }
            while (!st.empty() && i > st.top()) {
                if (st.top() < prev) {
                    return false;
                }
                prev = st.top();
                st.pop();
            }
            st.push(i);
        }
        return true;
    }
};
