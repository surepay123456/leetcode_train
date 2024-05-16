#include <climits>
#include <stack>
class MinStack {
public:
    MinStack() {
    stackMin.push(INT_MAX);
    }
    
    void push(int val) {
        stack.push(val);
        stackMin.push(std::min(stackMin.top(), val));
    }
    
    void pop() {
        stack.pop();
        stackMin.pop();

    }
    
    int top() {
        return stack.top();

    }
    
    int getMin() {
        return stackMin.top();

    }
private: 
    std::stack<int> stack;
    std::stack<int> stackMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */