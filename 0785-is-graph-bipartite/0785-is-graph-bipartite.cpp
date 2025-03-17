class Solution {
public:
    bool dfs(int idx, int col, vector<int>&vis, vector<vector<int>>& graph) {
        vis[idx] = col; 
        
        for(auto it : graph[idx]) {
            if(vis[it] == -1) {
                if(dfs(it, !col, vis, graph) == false) return false; 
            }

            else if(vis[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, -1);

        for(int i = 0 ; i < v ; i++) {
            if(vis[i] == -1) {
                if(dfs(i, 0, vis, graph) == false) return false;
            }
        }

        return true;
    }
};