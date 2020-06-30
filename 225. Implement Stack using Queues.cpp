class MyStack {
public:
    
    queue<int> q = queue<int>();
    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> temp = queue<int>();
        int size = q.size();
        for (int i = 0; i < size - 1; ++i) {
            temp.push(q.front());
            q.pop();
        }
        int result = q.front();
        q = temp;
        return result;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> temp = queue<int>();
        int size = q.size();
        for (int i = 0; i < size - 1; ++i) {
            temp.push(q.front());
            q.pop();
        }
        int result = q.front();
        temp.push(q.front());
        q = temp;
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
