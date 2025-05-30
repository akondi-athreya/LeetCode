class Solution {
public:
    int n;
    void dfs(vector<int>&edges, int node, vector<int>&dist, vector<bool>&visited) {
        visited[node] = true;
        int v = edges[node];
        if(v != -1 && !visited[v]) {
            visited[v] = true;
            dist[v] = 1 + dist[node];
            dfs(edges, v, dist, visited);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        vector<bool> visit1(n, false);
        vector<bool> visit2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, visit1);
        dfs(edges, node2, dist2, visit2);
        
        int res = -1;
        int ans = INT_MAX;

        for(int i = 0 ; i < n ; i++) {
            int x = max(dist1[i], dist2[i]);
            
            if(ans > x) {
                ans = x;
                res = i;
            }
        }
        return res;
    }
};