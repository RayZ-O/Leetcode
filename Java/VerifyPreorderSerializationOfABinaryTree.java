// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a
// binary search tree.

// You may assume each number in the sequence is unique.

public class VerifyPreorderSerializationOfABinaryTree {
    public boolean verifyPreorder(int[] preorder) {
        Stack<Integer> st = new Stack<>();
        int cur = Integer.MIN_VALUE;
        for (int i : preorder) {
            if (i < cur) {
                return false;
            }
            while (!st.empty() && i > st.peek()) {
                cur = st.peek();
                st.pop();
            }
            st.push(i);
        }
        return true;
    }
}
