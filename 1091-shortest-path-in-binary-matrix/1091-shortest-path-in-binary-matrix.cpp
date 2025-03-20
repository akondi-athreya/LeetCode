class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0) return -1;
        if(m == 1 && n == 1) return 1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        q.push({1, {0, 0}});
        dist[0][0] = 1;

        vector<int> dr = {0, 0, 1, -1, -1, 1, 1, -1};
        vector<int> dc = {1, -1, 0, 0, 1, 1, -1, -1};

        while(!q.empty()) {
            auto ff = q.front();
            q.pop();
            int dis = ff.first;
            int row = ff.second.first;
            int col = ff.second.second;

            for(int i = 0 ; i < 8 ; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dis + 1;

                        if(nr == m-1 && nc == n-1) return dist[nr][nc];

                        q.push({dist[nr][nc], {nr, nc}});
                    }
            }
        }

        return -1;
    }
};