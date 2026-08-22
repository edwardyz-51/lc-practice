class MinStack {
private: 
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
    stack.push(val);

    if (minStack.empty()) {
        // If there's no current min, this value is the new min
        minStack.push(val);
    } else {
        if (val < minStack.top()) {
            minStack.push(val);  // new value is smaller, so new min
        } else {
            minStack.push(minStack.top()); // keep the existing min
        }
    }
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
