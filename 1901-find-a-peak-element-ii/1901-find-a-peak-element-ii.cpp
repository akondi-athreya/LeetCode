class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;
        while (low <= high) {
            int mid = (low + high) / 2;

            int mx = -1;
            int idx = -1;
            for (int i = 0 ; i < n ; i++) {
                if (mat[i][mid] > mx) {
                    mx = mat[i][mid];
                    idx = i;
                }
            }
            //
            int left = mid-1 >= 0 ? mat[idx][mid-1] : -1;
            int right = mid+1 < m ? mat[idx][mid+1] : -1;

            if (mat[idx][mid] > left && mat[idx][mid] > right) {
                return {idx, mid};
            }
            else if (mat[idx][mid] < left) {
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return {-1, -1};
    }
};