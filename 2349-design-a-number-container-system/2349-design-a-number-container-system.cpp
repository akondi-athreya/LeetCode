class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    unordered_map<int, int> mp2;
    NumberContainers() {}

    void change(int i, int num) {
        mp2[i] = num;
        mp[num].push(i);
    }

    int find(int num) {
        if (mp.find(num) == mp.end()) {
            return -1;
        }
        auto& minHeap = mp[num];
        while (!minHeap.empty()) {
            int i = minHeap.top();
            if (mp2[i] == num) {
                return i;
            }
            minHeap.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */