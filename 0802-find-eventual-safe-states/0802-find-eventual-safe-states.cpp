class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> ind(V);
        for(int i = 0 ; i < V ; i++) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
                ind[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0 ; i < V ; i++) {
            if(ind[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]) {
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};