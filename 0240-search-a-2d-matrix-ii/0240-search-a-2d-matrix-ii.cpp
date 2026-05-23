class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1 && m == 1 && matrix[0][0] == target) return true;

        int i = 0, j = m-1;

        while (i < n && j >= 0) {
            int x = matrix[i][j];
            if (x == target) return true;

            else if (x < target) {
                i++;
            }
            else j--;
        }
        return false;
    }
};