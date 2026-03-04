class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int cnt = 0;

        queue<pair<int, int>> q;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (mat[i][j] == 1) q.push({i, j});
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int line_x = 0, line_y = 0;
            for (int i = 0 ; i < n ; i++) {
                if (i != x && mat[i][y] == 0) line_x++;
            }
            for (int j = 0 ; j < m ; j++) {
                if (j != y && mat[x][j] == 0) line_y++;
            }
            if (line_x == n-1 && line_y == m-1) cnt++;
        }
        return cnt;
    }
};