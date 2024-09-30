class CustomStack {
    vector<int> vec;
    int top;
public:
    CustomStack(int maxSize) {
        vec.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if (top < (int)(vec.size()) - 1) {
            vec[++top] = x;
        }
    }
    int pop() {
        if (top >= 0) {
            return vec[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int limit = min(k, top + 1);
        for (int i = 0; i < limit; i++) {
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */