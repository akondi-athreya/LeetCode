class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int cnt = 0;
        int sml = INT_MAX;
        long long ans = 0;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                ans += abs(matrix[i][j]);

                if (matrix[i][j] < 0) cnt++;

                sml = min(sml, abs(matrix[i][j]));
            }
        }

        if (cnt & 1) return ans - 2*sml;

        return ans;
    }
};