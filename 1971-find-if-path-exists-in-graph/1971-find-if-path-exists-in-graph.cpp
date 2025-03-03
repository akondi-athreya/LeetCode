class Solution {
public:
    class DisjointUnionSets {
        vector<int> rank, parent;
    public:
        DisjointUnionSets(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for (int i = 0 ; i <= n ; i++) {
                parent[i] = i;
            }
        }
        int findUpar(int n) {
            if(n == parent[n]){
                return n;
            }
            return parent[n] = findUpar(parent[n]);
        }
        void unionSet(int u, int v) {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }


    };
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointUnionSets dus(n);
        for(int i = 0 ; i < edges.size() ; i++) {
            dus.unionSet(edges[i][0], edges[i][1]);
        }
        if(dus.findUpar(source) == dus.findUpar(destination)) return true;
        return false;
    }
};