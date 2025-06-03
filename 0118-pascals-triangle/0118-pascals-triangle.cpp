class Solution {
public:
    vector<int> fun(int row) {
        long long ans = 1;
        vector<int> ar;
        ar.push_back(1);
        for(int col = 1 ; col<row ; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ar.push_back(ans);
        }
        return ar;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1 ; i <= numRows ; i++) {
            ans.push_back(fun(i));
        }
        return ans;
    }
};