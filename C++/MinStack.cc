 // Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 //    push(x) -- Push element x onto stack.
 //    pop() -- Removes the element on top of the stack.
 //    top() -- Get the top element.
 //    getMin() -- Retrieve the minimum element in the stack.

class MinStack {
	vector<int> stack;
	vector<int> min;
public:
	MinStack() : min{0} {
		stack.reserve(100);
		min.reserve(100);
	}
    void push(int x) {
    	if (stack.empty()) {
        	min.push_back(x);
        } else if (x <= min.back()) {
    		min.push_back(x);
        } 
        stack.push_back(x);  
    }

    void pop() {
        if (!stack.empty()) {        	
        	if(stack.back() == min.back()) {
        		min.pop_back();
        	}
        	stack.pop_back();  	
        }
    }

    int top() {
        if (!stack.empty()) {
        	return stack.back();
        } 
    }

    int getMin() {
        if (!stack.empty()) {
        	return min.back();
        }
    }
};