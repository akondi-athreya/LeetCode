class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int total = 0;
        for(int i = 0 ; i < m ; i++ ) {
            for(int j = 0 ; j < n ; j++ ) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int cnt = 0;
        int ans = 0;

        while(!q.empty()) {
            int k = q.size();
            cnt += k;
            while(k--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0 ; i < 4 ; i++ ) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if( nx < 0 || ny < 0 ||
                    nx >= m || ny >= n || grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()) ans++;
        }

        if(total == cnt) return ans;
        return -1;
    }
};