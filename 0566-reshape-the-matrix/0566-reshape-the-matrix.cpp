class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m*n != r*c) return mat;

        vector<vector<int>> ans(r, vector<int>(c));
        int i = 0, j = 0, k = 0, l = 0;
        int cnt = m*n;
        while (cnt--) {
            if (j == n) {
                j = 0;
                i++;
            }
            if (l == c) {
                l = 0;
                k++;
            }
            if (i < m && j < n && k < r && l < c) {
                ans[k][l] = mat[i][j];
                j++;
                l++;
            }
        }
        return ans;
    }
};