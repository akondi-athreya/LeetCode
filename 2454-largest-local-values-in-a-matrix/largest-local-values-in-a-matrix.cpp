class Solution {
public:
    int fun(vector<vector<int>>& grid , int r , int c){
        int mx = INT_MIN;
        for(int i=r ; i<=r+2 ; i++){
            for(int j=c ; j<=c+2 ; j++){
                mx = max(mx , grid[i][j]);
            }
        }
        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        for(int i=0 ; i<grid.size()-2 ; i++){
            vector<int> v;
            for(int j=0 ; j<grid.size()-2 ; j++){
                v.emplace_back(fun(grid , i , j));
            }
            res.emplace_back(v);
        }
        return res;
    }
};