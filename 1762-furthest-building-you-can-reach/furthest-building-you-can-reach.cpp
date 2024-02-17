class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>> max_heap;
        int n = heights.size();
        for (int i=1; i<n; ++i) {
            if (heights[i] <= heights[i-1])
                continue;
            int d = heights[i] - heights[i-1];
            bricks -= d;
            max_heap.push(d);
            if (bricks < 0) {
                if (ladders == 0)
                    return i-1;
                int msf = max_heap.top();
                bricks += msf;
                max_heap.pop();
                --ladders;
            }
        }
        return n-1;
    }
};