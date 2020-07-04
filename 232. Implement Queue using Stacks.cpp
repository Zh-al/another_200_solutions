class MyQueue {
public:
    
    stack<int> s;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        while(!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        int result = temp.top();
        temp.pop();
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> temp;
        while(!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        int result = temp.top();
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
