class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return dis;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newdist = max(abs(heights[nr][nc] - heights[row][col]), dis);

                    if(newdist < dist[nr][nc]) {
                        dist[nr][nc] = newdist;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};