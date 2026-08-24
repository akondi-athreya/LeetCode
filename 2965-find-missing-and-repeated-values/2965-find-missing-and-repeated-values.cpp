class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n * n;
        
        vector<int> v(m + 1, 0);
        int a = -1, b = -1;
        
        for (auto& row : grid) {
            for (int i : row) {
                v[i]++;
                if (v[i] == 2) {
                    a = i;
                }
            }
        }
        
        for (int i = 1 ; i <= m ; i++) {
            if (v[i] == 0) {
                b = i;
                break;
            }
        }
        
        return {a, b};
    }
};