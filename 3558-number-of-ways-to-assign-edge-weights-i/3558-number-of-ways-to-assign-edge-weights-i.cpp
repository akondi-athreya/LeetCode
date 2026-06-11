class Solution {
public:
    int mod = 1e9+7;
    int calculate_depth(vector<vector<int>>&adj, int curr, int parent) {
        int depth = 0;

        for (int it : adj[curr]) {
            if (it != parent) {
                depth = max(depth, calculate_depth(adj, it, curr) + 1);
            }
        }

        return depth;
    }
    long long find_pow(int x, int y) {
        if (y == 0) return 1;
        
        long long mid = find_pow(x, y/2);

        if (y % 2 == 0) {
            return (mid * mid) % mod;
        }
        else {
            return (mid * mid * x) % mod;
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int V = 0;
        for (auto &it : edges) {
            V = max(V, max(it[0], it[1]));
        }

        vector<vector<int>> adj(V+1);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = calculate_depth(adj, 1, 0);

        int ans = (int)find_pow(2, depth-1);
        
        return ans;
    }
};