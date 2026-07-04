class Solution {
public:
    void dfs(int u, unordered_map<int, vector<pair<int, int>>>&adj, vector<bool>&visit, int & res) {
        visit[u] = true;

        for (auto& ppair : adj[u]) {
            int v = ppair.first;
            int d = ppair.second;

            res = min(res, d);

            if (!visit[v]) {
                dfs(v, adj, visit, res);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            adj[u].emplace_back(make_pair(v, d));
            adj[v].emplace_back(make_pair(u, d));
        }

        int res = INT_MAX;
        vector<bool> visit(n, false);

        dfs(1, adj, visit, res);
        return res;
    }
};