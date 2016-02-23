// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

class MinStack {
    Stack<Integer> st = new Stack<>();
    Stack<Integer> mst = new Stack<>();

    public void push(int x) {
        st.push(x);
        if (mst.isEmpty() || x <= mst.peek()) {
            mst.push(x);
        }
    }

    public void pop() {
        int t = st.pop();
        if (t == mst.peek()) {
            mst.pop();
        }
    }

    public int top() {
        return st.peek();
    }

    public int getMin() {
        return mst.peek();
    }
}
