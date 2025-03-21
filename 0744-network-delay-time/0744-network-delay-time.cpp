class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        set<pair<int, int>> st;
        vector<int> dist(n+1, 1e9);
        st.insert({k, 0});
        dist[k] = 0;
        dist[0] = -1;

        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.first;
            int cost = it.second;
            st.erase(it);

            for(auto ite : adj[node]) {
                int adjNode = ite.first;
                int edwt = ite.second;

                if(cost + edwt < dist[adjNode]) {
                    dist[adjNode] = cost + edwt;
                    st.insert({adjNode, cost + edwt});
                }
            }
        }
        int mx = -1;
        for(int i = 1 ; i < dist.size() ; i++) {
            if(dist[i] == 1e9) return -1;
            else if(i != k) mx = max(dist[i], mx);
        }
        return mx;
    }
};