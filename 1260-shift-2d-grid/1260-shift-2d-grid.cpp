class Solution {
public:
    int posToVal(int r, int c, int n) {
        return r * n + c;
    }
    pair<int, int> valToPos(int num, int n) {
        return { num / n, num % n};
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                int nv = (posToVal(i, j, n) + k) % (m * n);
                pair<int, int> newpos = valToPos(nv, n);
                res[newpos.first][newpos.second] = grid[i][j];
            }
        }
        return res;
    }
};