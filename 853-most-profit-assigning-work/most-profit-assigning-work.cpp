class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        vector<pair<int,int>> v(n);
        priority_queue<int> pq;
        int ans = 0;
        for(int i=0;i<n;i++) v[i] = {difficulty[i],profit[i]};
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int i = 0;
        int j = 0;
        int m = difficulty.size();
        while(j<n){
            while(i<m && v[i].first<=worker[j]){
                pq.push(v[i].second);
                i++;
            }
            j++;
            if(pq.empty()) continue;
            ans+=pq.top();
        }
        return ans;
    }
};