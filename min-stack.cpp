class MinStack {
private:
    std::stack<int> stack = std::stack<int>();
    std::stack<int> minStack = std::stack<int>();
public:
    void push(int x) {
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
        stack.push(x);
    }
    
    void pop() {
        if (stack.top() == minStack.top()) {
            minStack.pop();
        }
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};