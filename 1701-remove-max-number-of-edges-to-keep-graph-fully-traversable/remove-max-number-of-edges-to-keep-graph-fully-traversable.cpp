class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i=1 ; i<=n ; i++){
                parent[i] = i;
            }
            components = n;
        }
        int find(int x) {
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        void Union (int x , int y){
            int x_parent = find(x);
            int y_parent = find(y);
            if(x_parent == y_parent) return;
            if(rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
            else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            }
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
        }
        bool isSingle(){
            return components == 1;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        auto lambda = [](vector<int>& vec1 , vector<int>& vec2) {
            return vec1[0] > vec2[0];
        };
        sort(begin(edges) , end(edges) , lambda);
        int ec = 0;
        for(auto &vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];
            if(type == 3){
                bool z = false;
                //alice
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u , v);
                    z = true;
                }
                //bob
                if(bob.find(u) != bob.find(v))  {
                    bob.Union(u , v);
                    z = true;
                }
                if(z == true) ec++;
            }
            else if(type == 2){
                //bob
                if(bob.find(u) != bob.find(v))  {
                    bob.Union(u , v);
                    ec++;
                }
            }
            else{
                //alice
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u , v);
                    ec++;
                }
            }
        }
        if(alice.isSingle() == true && bob.isSingle()){
            return edges.size() - ec;
        }
        return -1;
    }
};