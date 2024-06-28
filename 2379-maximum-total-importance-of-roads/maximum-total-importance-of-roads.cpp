class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> v(n,0);
        for(auto it : roads){
            int u = it[0] , z = it[1];
            v[u]++;
            v[z]++;
        }
        sort(v.begin() , v.end());
        long long ans=0 , res=1;
        for(auto it : v){
            ans+=it*res;
            res++;
        }
        return ans;
    }
};