class MyQueue {
public:
stack<int>eq;
stack<int>dq;
    MyQueue() {
        
    }
    
    void push(int x) {
        eq.push(x);
    }
    
    int pop() {
        while(!eq.empty()){
            dq.push(eq.top());
            eq.pop();
        }
        int k=dq.top();
        dq.pop();
        while(!dq.empty()){
            eq.push(dq.top());
            dq.pop();
        }
        return k;
    }
    
    int peek() {
        while(!eq.empty()){
            dq.push(eq.top());
            eq.pop();
        }
        int k=dq.top();
        while(!dq.empty()){
            eq.push(dq.top());
            dq.pop();
        }
        return k;
    }
    
    bool empty() {
        return eq.empty();
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