class MinStack {
private:
    struct data {
        int value;
        int currentMin;
    };
    
public:
    /** initialize your data structure here. */
    
    vector<data> stack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if (stack.size() == 0) {
            stack.push_back({x, x});
        } else {
            stack.push_back({x, min(getMin(), x)});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1].value;
    }
    
    int getMin() {
        return stack[stack.size() - 1].currentMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
