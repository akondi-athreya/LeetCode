class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indeg(n , 0);
        for(auto ele:edges){
            adj[ele[0]].push_back(ele[1]);
            indeg[ele[1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0)
            q.push(i);
        }
        vector<set<int>> ans(n);
        while(!q.empty()){
            int node = q.front(); q.pop();
            set<int> my = ans[node];
            for(auto ele:adj[node]){
                ans[ele].insert(node);
                for(auto it:my)
                ans[ele].insert(it);
                indeg[ele]--;
                if(indeg[ele] == 0) 
                q.push(ele);
            }
        }
        vector<vector<int>> res(n);
        for(int i = 0 ; i< n ;i++){
            for(auto ele:ans[i]){
                res[i].push_back(ele);
            }
        }
        return res;
    }
};