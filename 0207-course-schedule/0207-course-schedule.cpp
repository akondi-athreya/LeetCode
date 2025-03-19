class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        int V = numCourses;
        vector<int> ind(V, 0);
        for(int i = 0 ; i < V ; i++) {
            for(auto it : adj[i]) {
                ind[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < V ; i++) {
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

        if(ans.size() == V) return true;
        return false;
    }
};