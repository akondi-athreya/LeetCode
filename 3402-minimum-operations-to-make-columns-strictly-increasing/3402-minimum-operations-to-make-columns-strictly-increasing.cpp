class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        int cnt = 0;
        int n = grid.size() , m = grid[0].size();
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i-1][j] >= grid[i][j] ){
                    ans = grid[i-1][j] - grid[i][j] + 1;
                    grid[i][j] = ans+grid[i][j];
                    cnt += ans;
                }
            }
        }
        return cnt;
    }
};