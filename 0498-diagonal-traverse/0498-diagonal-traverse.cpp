class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;

        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(!(mp.count(i+j))) {
                    mp[i+j] = {mat[i][j]};
                } else {
                    mp[i+j].push_back(mat[i][j]);
                }
            }
        }
        bool flag = true;
        vector<int> ans;
        for(auto &it : mp) {
            if(flag) {
                for(int j = it.second.size() - 1 ; j >= 0 ; j--) {
                    ans.emplace_back(it.second[j]);
                }
            } else {
                for(int num : it.second) {
                    ans.emplace_back(num);
                }
            }
            flag = !flag;
        }

        return ans;
    }
};