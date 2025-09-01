class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq;
        for (int i = 0 ; i < n ; i++) {
            double curr = (double)classes[i][0]/classes[i][1];
            double newCurr = (double)(classes[i][0] + 1)/(classes[i][1] + 1);

            double change = newCurr - curr;
            pq.push({change, i});
        }

        while (extraStudents--) {
            auto it = pq.top();
            pq.pop();

            double change = it.first;
            int idx = it.second;
            
            classes[idx][0]++;
            classes[idx][1]++;

            double curr = (double)classes[idx][0]/classes[idx][1];
            double newCurr = (double)(classes[idx][0] + 1)/(classes[idx][1] + 1);

            change = newCurr - curr;
            pq.push({change, idx});
        }

        double ans = 0.0;
        for (int i = 0 ; i < n ; i++) {
            ans += (double)classes[i][0]/classes[i][1];
        }

        return ans/n;
    }
};