//  Implement the following operations of a stack using queues.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     empty() -- Return whether the stack is empty.

// Notes:

//     You must use only standard operations of a queue -- which means only push to back, peek/pop from 
//     front, size, and is empty operations are valid.
//     Depending on your language, queue may not be supported natively. You may simulate a queue by using 
//     a list or deque (double-ended queue), as long as you use only standard operations of a queue.
//     You may assume that all operations are valid (for example, no pop or top operations will be called 
//     on an empty stack).


class Stack {
    vector<queue<int>> qs { queue<int>(), queue<int>() };
    int cur_q = 0;
    void transfer(vector<queue<int>>& qs, int cur_q) {
        while (qs[cur_q].size() > 1) {
            qs[!cur_q].push(qs[cur_q].front());
            qs[cur_q].pop();
        }
    }
public:
    // Push element x onto stack.
    void push(int x) {
        qs[cur_q].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        transfer(qs, cur_q);
        qs[cur_q].pop();
        cur_q = !cur_q;
    }

    // Get the top element.
    int top() {
        transfer(qs, cur_q);
        return qs[cur_q].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return qs[0].empty() && qs[1].empty();
    }
};