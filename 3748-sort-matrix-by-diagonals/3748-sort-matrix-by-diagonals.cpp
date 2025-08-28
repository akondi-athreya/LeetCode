class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                int diag = i - j;
                mp[diag].push_back(grid[i][j]);
            }
        }

        for(auto &it : mp) {
            if (it.first >= 0) {
                sort(begin(it.second), end(it.second));
            } else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                int diag = i-j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();
            }
        }

        return grid;
    }
};