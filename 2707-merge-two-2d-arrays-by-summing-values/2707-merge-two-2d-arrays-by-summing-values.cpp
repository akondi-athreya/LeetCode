class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> mp;

        for (auto& it : nums1) {
            mp[it[0]] = it[1];
        }

        for (auto& it : nums2) {
            mp[it[0]] += it[1];
        }

        for (auto& it : mp) {
            vector<int> v = {it.first, it.second};
            ans.push_back(v);
        }

        return ans;
    }
};