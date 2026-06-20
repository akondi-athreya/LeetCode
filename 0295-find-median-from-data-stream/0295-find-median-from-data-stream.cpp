class MedianFinder {
public:
    priority_queue<int> leftq; // max_heap
    priority_queue<int, vector<int>, greater<int>> rightq; // min_heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftq.empty() || num < leftq.top()) {
            leftq.push(num);
        }
        else {
            rightq.push(num);
        }

        if (abs((int)leftq.size() - (int)rightq.size()) > 1) {
            rightq.push(leftq.top());
            leftq.pop();
        }
        else if (leftq.size() < rightq.size()){
            leftq.push(rightq.top());
            rightq.pop();
        }
    }
    
    double findMedian() {
        if (leftq.size() == rightq.size()) {
            return (double)(leftq.top() + rightq.top())/2;
        }
        return (double)leftq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */