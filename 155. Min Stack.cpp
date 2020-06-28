class MinStack {
public:
    /** initialize your data structure here. */
    
    vector<int> data;
    int min = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
        if (x < min) {
            min = x;
        }
    }
    
    void pop() {
        int topEl = top();
        data.pop_back();
        if (topEl == min) {
            findMin();
        }
    }
    
    int top() {
        return data[data.size() - 1];
    }
    
    int getMin() {
        return min;
    }
    
    void findMin() {
        min = INT_MAX;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] < min) {
                min = data[i];
            }
        }
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
