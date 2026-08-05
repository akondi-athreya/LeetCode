class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int r, int c) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == -1) {
            return 0;
        }
        grid[i][j] = -1;

        return (dfs(grid, i+1, j, r, c)) + 
        (dfs(grid, i-1, j, r, c)) + (dfs(grid, i, j+1, r, c)) + (dfs(grid, i, j-1, r, c));
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int ans = 0;
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (grid[i][j] == 1) {
                    ans += dfs(grid, i, j, r, c);
                }
            }
        }
        return ans;
    }
};