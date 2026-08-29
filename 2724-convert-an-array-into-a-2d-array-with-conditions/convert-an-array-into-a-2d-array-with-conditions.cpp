class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> ans;

        for (int num : nums) {
            mp[num]++;
            if (mp[num] > ans.size()) ans.push_back({});
            ans[mp[num] - 1].push_back(num);
        }
        return ans;
    }
};