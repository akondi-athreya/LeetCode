class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> adj(N);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ind(N, 0);
        for(int i = 0 ; i < N ; i++) {
            for(auto it : adj[i]) {
                ind[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < N ; i++) {
            if(ind[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]) {
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }
        if(ans.size() == N) return ans;
        return {};
    }
};