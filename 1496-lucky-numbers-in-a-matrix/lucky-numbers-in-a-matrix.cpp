class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMin;
        for (int row = 0; row < m; row++) {

            int rMin = INT_MAX;
            for (int col = 0; col < n; col++) {
                rMin = min(rMin, matrix[row][col]);
            }
            rowMin.emplace_back(rMin);
        }

        vector<int> colMax;
        for (int col = 0; col < n; col++) {

            int cMax = INT_MIN;
            for (int row = 0; row < m; row++) {
                cMax = max(cMax, matrix[row][col]);
            }
            colMax.emplace_back(cMax);
        }

        vector<int> ans;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col]) {
                    ans.emplace_back(matrix[row][col]);
                }
            }
        }

        return ans;
    }
};