class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> v(n, 0);
        int cnt = 0;
        for (int i = 1 ; i < n ; i++) {
            if (nums[i] - nums[i-1] > maxDiff) cnt++;
            v[i] = cnt;
        }
        vector<bool> ans;
        for (auto& it : queries) {
            ans.emplace_back(v[it[0]] == v[it[1]]);
        }
        return ans;
    }
};